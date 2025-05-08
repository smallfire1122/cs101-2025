#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string m_DriveMode;

private:
    int m_MaxSeating;
    int m_price;
    void m_UpdatePrice(int base = 500000) {
        m_price = base + m_MaxSeating * 10000;
    }

public:
    string m_brand;
    string m_model;
    int m_year;

Car(string x, string y, int z, int s) {
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_UpdatePrice();
    }

    int get_MaxSeating() { return m_MaxSeating; }
    int get_Price() { return m_price; }
    string get_DriveMode() { return m_DriveMode; }
};
class BMW_Car : public Car {
public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s) {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
        cout << m_brand << " : Drive Mode = " << get_DriveMode() << endl;
    }
};
class AUDI_Car : public Car {
public:
    AUDI_Car(string y, int z, int s) : Car("Audi", y, z, s) {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << " : Drive Mode = " << get_DriveMode() << endl;
    }
};
class BENZ_Car : public Car {
public:
    BENZ_Car(string y, int z, int s) : Car("Benz", y, z, s) {
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << " : Drive Mode = " << get_DriveMode() << endl;
    }
};

int main() {
    BMW_Car("X5", 2023, 6);
    AUDI_Car("A1", 2023, 5);
    BENZ_Car("C300", 2022, 5);
    return 0;
}
