#pragma once
#include <string>
#include <fstream>
#include <vector>
//Klasa File
//* RAII
//* c - tor przyjmujacy nazwê pliku, rzuca wyj¹tek gdy nie uda siê otwrzyc pliku
//* d - tor zamyka plik
//* Mile widziane funkjce szablonowe zapisuj¹ce / wczytj¹ce dowonly typ danych(wspieraj¹cy operator << >>)
//* Zak³adamy, ze 1 linia pliku 1 wartoœæ(dane nie mog¹ zwieraæ bia³ych znaków)
//* Zak³adamy, ¿e u¿ytkownik zna format pliku i bêdzie wczytywa³ ró¿ne typy wed³ug znanej sobie kolejnoœci
//np :
//string
//int
//double
//int
//* Dodaj klase Pracownik(imie, nazwisko, losowy numer pracownika, wysokoœæ pensji)
//* Numer pracownika ma siê generowaæ losowo podczas tworznia nowego pracownika, dla u³atwienia mog¹ siê powtarzaæ
//* warto dodaæ operator << i >>
//*U¿yj klasy File do zapisania danych 10 pracowników
//* Wczytaj za pomoc¹ tej klasy te dane do wektora a nastêpnie wypisz pracowników posortowanych wed³ug wysokoœci pensji
class Employee;
class File {
private:
	std::string _fileName;
	//std::fstream _file(_fileName);
public:
	File(const std::string& fileName);
	~File();
	void readDataToVector(Employee & vector);
	void saveData(Employee& empl);
	void printVector();
};

class Employee {
public:
	std::string _name, _surname;
	int _employeeNumber, _salary;
	std::vector <Employee> vector;
	Employee(std::string name, std::string surname, int salary);
};