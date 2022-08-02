#include <iostream>
#include "File.hpp"
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>
int main() {
    File file("C:\\Users\\jwitu\\OneDrive\\Pulpit\\SDA\\CPPZaawansowanyZad\\employee.txt");

    Employee e1("Jan", "Kowalski", 4000);
    Employee e2("Joanna", "Nowak", 5000);
    Employee e3("Alicja", "Zielona", 7400);
    Employee e4("Piotr", "Malinowski", 3000);
    Employee e5("Tomasz", "Piotrowski", 4120);
    file.saveData(e1);
    file.saveData(e2);
    file.saveData(e3);
    file.saveData(e4);
    file.saveData(e5);

    file.readData();

}