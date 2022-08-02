#include <iostream>
#include "File.hpp"
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>

File::File(const std::string& fileName) : _fileName(fileName)/*, _file(fileName)*/ {
	std::fstream file(_fileName);
	try {
		file.is_open();
	}
	catch (std::ios_base::failure& e) {
		std::cout << "Unexpected exception caught: " << e.what() << std::endl;
	}
}

void File::printVector()
{

}

File::~File()
{
	std::fstream file(_fileName);
	file.close();
}
//zrobic template
//*Wczytaj za pomoc¹ tej klasy te dane do wektora
void File::readDataToVector(Employee& vector)
{
	std::ifstream _file(_fileName);
	while (_file.good() && !_file.eof()) {
		std::string str1, str2;
		int int1, int2;
		_file >> str1 >> str2 >> int1 >> int2;
		std::cout << str1 << " " << str2 << " " << " " << int1 << " " << int2 << "\n";
	}
}

//zrobic template
////*U¿yj klasy File do zapisania danych 10 pracowników
void File::saveData(Employee& empl)
{
	std::ofstream _file(_fileName, std::ios::out | std::ios::app);
		if (_file.good()) {
			_file << empl._name  << " " << empl._surname << " " << empl._salary << " " << empl._employeeNumber<< "\n";
		}
}

Employee::Employee(std::string name, std::string surname, int salary) : _name(name), _surname(surname), _salary(salary)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 100);
	_employeeNumber = distrib(gen);
}


