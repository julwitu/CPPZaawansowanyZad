// RegexPlateNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <regex>

std::string inputPlate() {
    std::string plateNumber = "";
    std::cout << "Podaj numer rejestracyjny: " << std::endl;
    std::cin >> plateNumber;
    return plateNumber;
}

bool checkPlateNumber(const std::string& plateNumber) {
    std::regex plateRegex("^[A - Z]{2,3}[0 - 9]{4}$");
    return std::regex_match(plateNumber, plateRegex);
}

int main()
{
    std::string plateNumber = inputPlate();
    std::cout << "Zgodnosc numeru rejestracyjnego: " << checkPlateNumber(plateNumber);
}


