#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

class Address {
private:
    std::string city;
    std::string street;
    int home;
    int apartments;
    std::string fullAddress;

public:
    Address(std::string setCity, std::string setStreet, int setHome, int setApartments)
        : city(setCity), street(setStreet), home(setHome), apartments(setApartments)
    {
    }

    std::string getFullAddress() {
        fullAddress = city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(apartments);
        return fullAddress;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inFile("in.txt");
    if (!inFile.is_open()) {
        std::cerr << "Не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int N;
    inFile >> N;
    inFile.ignore();

    Address** addresses = new Address * [N];

    // Чтение адресов из файла
    for (int i = 0; i < N; i++) {
        std::string city;
        std::string street;
        int home;
        int apartment;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> home;
        inFile >> apartment;
        inFile.ignore(); 

        addresses[i] = new Address(city, street, home, apartment);
    }
    inFile.close();

    std::ofstream outFile("out.txt");
    outFile << N << std::endl;
    for (int i = N - 1; i >= 0; i--) {
        outFile << addresses[i]->getFullAddress() << std::endl;
        delete addresses[i];
    }
    delete[] addresses;

    outFile.close();

    return 0;
}