//1) Реализовать иерархию классов "Транспортное средство".Базовый класс - транспорт, 
// производные - самолёт, судно, грузовик, велосипед и легковой автомобиль.
//Метод вывода и метод расхода топлива реализовать как virtual.
// Реализовать меню для создания объектов.Объекты создаются через единственный указатель на базовый класс.

#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string model;

public:
    Transport(string model) {
        SetModel(model);
    }

    string GetModel() const {
        return model;
    }

    void SetModel(string newModel) {
        model = newModel;
    }

    virtual void DisplayInfo() const {
        cout << "Модель: " << model << "\n";
    }

    virtual void FuelConsumption() const = 0;

    virtual ~Transport() {}
};

class Airplane : public Transport {
public:
    Airplane(const string& model) : Transport(model) {}

    void DisplayInfo() const override {
        Transport::DisplayInfo();
        cout << "Тип: Самолёт\n";
    }

    void FuelConsumption() const override {
        cout << "Самолёт - это очень дорогое удовольствие\n";
    }
};

class Ship : public Transport {
public:
    Ship(const string& model) : Transport(model) {}

    void DisplayInfo() const override {
        Transport::DisplayInfo();
        cout << "Тип: Судно\n";
    }

    void FuelConsumption() const override {
        cout << "Судно - тоже не из дешёвых вариантов\n";
    }
};

class Truck : public Transport {
public:
    Truck(const string& model) : Transport(model) {}

    void DisplayInfo() const override {
        Transport::DisplayInfo();
        cout << "Тип: Грузовик\n";
    }

    void FuelConsumption() const override {
        cout << "Расход топлива у грузовика - терпимый\n";
    }
};

class Bicycle : public Transport {
public:
    Bicycle(const string& model) : Transport(model) {}

    void DisplayInfo() const override {
        Transport::DisplayInfo();
        cout << "Тип: Велосипед\n";
    }

    void FuelConsumption() const override {
        cout << "Велосипед - это мой выбор\n";
    }
};

class Car : public Transport {
public:
    Car(const string& model) : Transport(model) {}

    void DisplayInfo() const override {
        Transport::DisplayInfo();
        cout << "Тип: Легковой автомобиль\n";
    }

    void FuelConsumption() const override {
        cout << "Автомобиль - это не роскошь, а средство передвижения\n";
    }
};

Transport* CreateTransport() {
    string model;
    int choice;

    cout << "Введите модель: ";
    cin >> model;

    cout << "Выберите тип транспорта:\n";
    cout << "1. Самолёт\n";
    cout << "2. Судно\n";
    cout << "3. Грузовик\n";
    cout << "4. Велосипед\n";
    cout << "5. Легковой автомобиль\n";

    cout << "Введите ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        return new Airplane(model);
    case 2:
        return new Ship(model);
    case 3:
        return new Truck(model);
    case 4:
        return new Bicycle(model);
    case 5:
        return new Car(model);
    default:
        throw "ERROR TYPE!\n";
    }
}

int main() {

    setlocale(0, "");

    const int maxSize = 100;
    Transport* transports[maxSize] = { nullptr };

    int menuChoice;
    int count = 0;

    do {
        cout << "1. Создать новое транспортное средство\n";
        cout << "2. Отобразить информацию о всех транспортных средствах\n";
        cout << "3. Выйти\n";

        cout << "Введите ваш выбор: ";
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            if (count < maxSize) {
                transports[count] = CreateTransport();
                count++;
            }
            else {
                cout << "Достигнут максимальный размер массива. Создание новых объектов невозможно.\n";
            }
            break;
        case 2:
            for (int i = 0; i < count; ++i) {
                transports[i]->DisplayInfo();
                transports[i]->FuelConsumption();
                cout << "\n";
            }
            break;
        case 3:
            for (int i = 0; i < count; ++i) {
                delete transports[i];
            }
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }

    } while (menuChoice != 3);
}