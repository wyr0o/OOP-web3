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
        : city{ setCity }, street{ setStreet }, home{ setHome }, apartments(setApartments)
    {
    }

    std::string getFullAddress() {
        fullAddress = city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(apartments);
        return fullAddress;
    }

    std::string getCity() const {
        return city;
    }
};

void sort(Address** addresses, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (addresses[j]->getCity() > addresses[j + 1]->getCity()) {
                std::swap(addresses[j], addresses[j + 1]);
            }
        }
    }
}

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

    sort(addresses, N);

    std::ofstream outFile("out.txt");
    outFile << N << std::endl;
    for (int i = 0; i < N; i++) {
        outFile << addresses[i]->getFullAddress() << std::endl;
        delete addresses[i]; 
    }
    delete[] addresses;

    outFile.close();

    return 0;
}