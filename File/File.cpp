#include <iostream>
#include "File.hpp"
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>


File::File(const std::string& fileName) : _fileName(fileName), _file1(fileName), _file2(fileName, std::ios::out | std::ios::app) {
	if (_file1.is_open() && _file2.is_open()) {
		std::cout << "Plik zostal poprawnie otwarty" << std::endl;
	}
	else {
		std::cout << "Unexpected exception caught" << std::endl;
	}
}

File::~File()
{
	_file1.close();
	_file2.close();
}
//zrobic template
//*Wczytaj za pomoc¹ tej klasy te dane do wektora
void File::readData()
{

	std::vector <std::string> vector;
	while (_file1.good() && !_file1.eof()) {
		//std::string str1, str2;
		//int int1, int2;
		//_file1 >> str1 >> str2 >> int1 >> int2;
		std::string str;
		std::getline(_file1, str);
		vector.push_back(str);
	}

	std::for_each(vector.begin(), vector.end(),
		[](std::string str) {std::cout << str << "\n"; });

	//sort std::stoi str->int
}

//zrobic template
////*U¿yj klasy File do zapisania danych 10 pracowników
void File::saveData(Employee& empl)
{
	if (_file2.good()) {
		_file2 << empl._name << " " << empl._surname << " " << empl._salary << " " << empl._employeeNumber << "\n";
	}
}

Employee::Employee(std::string name, std::string surname, int salary) : _name(name), _surname(surname), _salary(salary)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 100);
	_employeeNumber = distrib(gen);
}


