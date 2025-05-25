#pragma once
#include "Money.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Money> readFromFile(const string& filename) {
    vector<Money> data;
    fstream file(filename, ios::in);
    if (!file) return data;

    Money m;
    while (file >> m) {
        data.push_back(m);
    }
    file.close();
    return data;
}

void writeToFile(const string& filename, const vector<Money>& data) {
    fstream file(filename, ios::out | ios::trunc);
    for (const auto& m : data) {
        file << m;
    }
    file.close();
}

void deleteEquals(const string& filename, const Money& value) {
    auto data = readFromFile(filename);
    data.erase(remove_if(data.begin(), data.end(),
        [&value](const Money& m) { return m == value; }), data.end());
    writeToFile(filename, data);
}

void increaseEquals(const string& filename, const Money& value) {
    auto data = readFromFile(filename);
    for (auto& m : data) {
        if (m == value) m.increase();
    }
    writeToFile(filename, data);
}

void addAfterPosition(const string& filename, int pos, int k) {
    auto data = readFromFile(filename);
    if (pos < 0 || pos >= data.size()) return;

    Money newMoney;
    cout << "Enter " << k << " денежные значения (формат: рубли,копейки):" << endl;
    for (int i = 0; i < k; ++i) {
        cin >> newMoney;
        data.insert(data.begin() + pos + 1 + i, newMoney);
    }
    writeToFile(filename, data);
}
