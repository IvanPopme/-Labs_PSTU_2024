#include "Money.h"

ostream& operator<<(ostream& os, const Money& m) {
    os << m.rubles << "," << (m.kopecks < 10 ? "0" : "") << m.kopecks;
    return os;
}

istream& operator>>(istream& is, Money& m) {
    char sep;
    is >> m.rubles >> sep >> m.kopecks;
    m.normalize();
    return is;
}

fstream& operator<<(fstream& ofs, const Money& m) {
    ofs << m.rubles << " " << m.kopecks << endl;
    return ofs;
}

fstream& operator>>(fstream& ifs, Money& m) {
    ifs >> m.rubles >> m.kopecks;
    m.normalize();
    return ifs;
}
