include "Money.h"
#include "file_work.h"
#include <iostream>


using namespace std;

void displayMenu() {
    cout << "\nMenu:\n"
        << "1. Cоздать файл\n"
        << "2. Отобразить файл\n"
        << "3. Удалить записи, равные значению\n"
        << "4. Увеличьте записи, равные значению, на 1,50\n"
        << "5. Добавьте K записей после позиции\n"
        << "0. Выход\n"
        << "Выберите опцию: ";
}

int main() {
  setlocale (LC_ALL,"RU");
    string filename;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите имя файла: ";
            cin >> filename;
            int count;
            cout << "Введите количество записей: ";
            cin >> count;

            vector<Money> data;
            Money m;
            cout << "Введите " << count << " денежные значения (формат: рубли,копейки):" << endl;
            for (int i = 0; i < count; ++i) {
                cin >> m;
                data.push_back(m);
            }
            writeToFile(filename, data);
            break;
        }
        case 2: {
            cout << "Введите имя файла: ";
            cin >> filename;
            auto data = readFromFile(filename);
            for (const auto& m : data) {
                cout << m << endl;
            }
            break;
        }
        case 3: {
            cout << "Введите имя файла: ";
            cin >> filename;
            Money value;
            cout << "Введите значение для увеличения (формат: рубли,копейки): ";
            cin >> value;
            deleteEquals(filename, value);
            break;
        }
        case 4: {
            cout << "Введите имя файла: ";
            cin >> filename;
            Money value;
            cout << "Введите значение для увеличения (формат: рубли,копейки): ";
            cin >> value;
            increaseEquals(filename, value);
            break;
        }
        case 5: {
            cout << "Введите имя файла: ";
            cin >> filename;
            int pos, k;
            cout << "Введите позицию (на основе 0): ";
            cin >> pos;
            cout << "Введите K: ";
            cin >> k;
            addAfterPosition(filename, pos, k);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
