#pragma once
#include <string>
#include <fstream>
#include <vector>
//Klasa File

//* Mile widziane funkjce szablonowe zapisuj�ce / wczytj�ce dowonly typ danych(wspieraj�cy operator << >>)
//* Zak�adamy, ze 1 linia pliku 1 warto��(dane nie mog� zwiera� bia�ych znak�w)
//* Zak�adamy, �e u�ytkownik zna format pliku i b�dzie wczytywa� r�ne typy wed�ug znanej sobie kolejno�ci
//np :
//string
//int
//double
//int
//* Dodaj klase Pracownik(imie, nazwisko, losowy numer pracownika, wysoko�� pensji)
//* Numer pracownika ma si� generowa� losowo podczas tworznia nowego pracownika, dla u�atwienia mog� si� powtarza�
//* warto doda� operator << i >>
//*U�yj klasy File do zapisania danych 10 pracownik�w
//* Wczytaj za pomoc� tej klasy te dane do wektora a nast�pnie wypisz pracownik�w posortowanych wed�ug wysoko�ci pensji
class Employee;
class File {
private:
	std::string _fileName;
	std::ifstream _file1;
	std::ofstream _file2;
public:
	File(const std::string& fileName);
	~File();
	void readData();
	void saveData(Employee& empl);
};

class Employee {
public:
	std::string _name, _surname;
	int _employeeNumber, _salary;
	static std::vector <Employee> vectorEmpl;
	Employee(std::string name, std::string surname, int salary);
};