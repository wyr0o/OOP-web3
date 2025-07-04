#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>


class adress
{
private:
	std::string city{};
	std::string street{};
	int home{};
	int apartments{};
	std::string fullAdress{};

public:
	adress(std::string setCity, std::string setStreet, int setHome, int setApartments) : city{ setCity }, street{ setStreet }, home{ setHome }, apartments(setApartments)
	{}

	std::string getFullAdress()
	{
		fullAdress = city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(apartments);
		return fullAdress;
	}

	std::string getCity() const
	{
		return city;
	}
};

void sort(adress** addresses, int size) {
	for (int i = 0; i < size - 1; ++i) {
		
		if (addresses[i]->getCity() > addresses[i + 1]->getCity()) {
			std::swap(addresses[i], addresses[i + 1]);
		}
		
	}
}


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string city{};
	std::string street{};
	int home{};
	int apartment{};


	std::ofstream inFile("C:/c++ netology/in.txt");

	int N{};
	std::cout << "Введите количество адресов: ";
	std::cin >> N;
	inFile << N << std::endl;

	adress** adresses = new adress * [N];

	std::cout << "Введите " << N << " адреса" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cin.ignore();

		std::cout << "Адрес: " << i + 1 << std::endl;
		std::cout << "Город: ";
		std::getline(std::cin, city);
		std::cout << "Улица: ";
		std::getline(std::cin, street);
		std::cout << "Дом: ";
		std::cin >> home;
		std::cout << "Квартира: ";
		std::cin >> apartment;

		adresses[i] = new adress(city, street, home, apartment);

		inFile << city << std::endl;
		inFile << street << std::endl;
		inFile << home << std::endl;
		inFile << apartment << std::endl;
	}
	inFile.close();
	for (int i = 0; i < N; i++)
	{

	}

	sort(adresses, N);

	std::ofstream outFile("C:/c++ netology/out.txt");
	outFile << N << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cin.ignore();
		outFile << adresses[i]->getFullAdress() << std::endl;
		delete adresses[i];
	}
	delete[] adresses;

	outFile.close();

	return 0;
}