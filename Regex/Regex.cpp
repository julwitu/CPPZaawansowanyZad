// 1. Wczytaj od u¿ytkownika ³añcuch znaków, a nastêpnie sprawdz czy jest to poprawny adres e-mail.

#include <iostream>
#include <regex>
bool checkEmail(const std::string& input) {
    std::regex emailRegex("^[a - z0 - 9_.]{3,}@[a - z0 - 9_] + .[a - z]{2,3}$");
    return std::regex_match(input, emailRegex);
}

int main()
{
    std::cout << "Podaj adres email: " << std::endl;
    std::string input;
    std::cin >> input;

    std::cout << "Zgodny wynik: " << std::endl;
    checkEmail(input);
}


