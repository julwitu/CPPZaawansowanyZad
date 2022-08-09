// Zad 4.
//Wczytaj plik customers.csv(Podczas pracy z tym zadaniem NIE NADPISUJ tego pliku)
//a.W wyniku b³edu w aplikacji, kilka osób jest wpisanych kilkukrotnie, przed rozpoczêciem pracy upewnij siê, ¿e usun¹³êœ zduplikowane wpisy. (Dobrych wpisów powinno byæ 1000)
//b.Proszê usuñ wpisy osób, które nie poda³y adresu e - mail.
//c.Potrzebujemy listê osób, które za³o¿y³o konta w naszym serwisie przy u¿yciu maila z domeny.edu.Zapisz ich dane do osobnego pliku edu.csv.Zachowaj format pliku Ÿród³owego
//d.Przygotuj statystykê firm wraz z liczb¹ osób tam zatrudnionych, którzy s¹ naszymi klientami.Zapisz j¹ do pliku companies.csv
//f.Zapisz poprawiony plik jako customers_fixed.csv

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
struct Customer {
    std::string _name, _surname, _mail, _company;
    Customer(std::string name, std::string surname, std::string mail, std::string company) : _name(name), _surname(surname), _mail(mail), _company(company) {
    }
};
 bool surnameSort (const Customer& customer1, const Customer& customer2)
 {
        return (customer1._surname[0] < customer2._surname[0]);
 }
 bool isEqual(const Customer& customer1, const Customer& customer2) {
     return(customer1._surname == customer2._surname);
 }
 bool hasNoMail(const Customer& customer) {
     return (customer._mail != "");
 }
int main()
{
    std::ifstream customersFile("cus.csv");
    std::string name;
    std::string surname;
    std::string mail;
    std::string company;
    std::vector<Customer>customers;
    if (customersFile.is_open()) {
        std::cout << "Plik zostal poprawnie wczytany" << std::endl;
    }
    else {
        std::cout << "Blad wczytywania pliku" << std::endl;
    }
    std::getline(customersFile, name);
    while (std::getline(customersFile, name, ',')) {
        std::getline(customersFile, surname, ',');
        std::getline(customersFile, mail, ',');
        std::getline(customersFile, company);
        customers.emplace_back(name, surname, mail, company);
    }
    
    std::sort(customers.begin(), customers.end(), surnameSort);
    // TODO usunac wypisywanie wektora
    std::for_each(customers.begin(), customers.end(), [](Customer& customers) {
        std::cout << customers._name << " " << customers._surname << " " << customers._mail << " " << customers._company << std::endl;
        });
    auto lastToRemove = std::unique(customers.begin(), customers.end(), isEqual);
    
    customers.erase(lastToRemove, customers.end());
    // TODO usunac wypisywanie wektora
    std::cout << std::endl;
    std::for_each(customers.begin(), customers.end(), [](Customer& customers) {
        std::cout << customers._name << " " << customers._surname << " " << customers._mail << " " << customers._company << std::endl;
        });

    std::cout << std::endl;
    std::cout << hasNoMail(customers[0]);
    



}

