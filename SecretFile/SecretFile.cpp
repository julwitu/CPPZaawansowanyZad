// Zad 3.
//Wczytaj plik secret_file.csv(Podczas pracy z tym zadaniem NIE NADPISUJ tego pliku).
//Do osobnego pliku wypisz wszystkie nazwy u¿ytkowników i ich has³a, które nie spe³niaj¹ naszych wymagañ :
//-minimum 8 znaków
//- przynajmniej 1 du¿a litera, 1 ma³a litera i 1 cyfra

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>

struct User {
    std::string _login, _password;
    User(std::string login, std::string password) : _login(login), _password(password) {
    }
};

int main()
{
    std::ifstream secretFile("secret_file.csv");

    if (!secretFile.is_open()) {
        std::cout << "Blad wczytywania pliku" << std::endl;
    }
    else {
        std::cout << "Plik zostal wczytany poprawnie" << std::endl;
    }
    std::string login;
    std::string password;

    std::vector <User> users;
    std::getline(secretFile, login);

    while (std::getline(secretFile, login, ',')) {
        std::getline(secretFile, password);
        users.emplace_back(login, password);
    }

    secretFile.close();
    
    std::vector <User> badUsers;
    auto checkPassword = [](const User &users) {
        std::regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$");
        return std::regex_match(users._password, passwordRegex);
    };
    std::copy_if(users.begin(), users.end(), std::back_inserter(badUsers), checkPassword);

    std::ofstream wrongUsers("wrongusers.csv", std::ios::out | std::ios::trunc);

    if (wrongUsers.is_open()) {
        if (wrongUsers.good()) {
            for (int i = 0; i < badUsers.size(); i++) {
                wrongUsers << badUsers[i]._login << ',' << badUsers[i]._password << "\n";
                std::cout << "Zapisano do pliku" << std::endl;
            }
        }
        else {
            std::cout << "Blad otwarcia pliku" << std::endl;
        }
    }
    wrongUsers.close();
}

