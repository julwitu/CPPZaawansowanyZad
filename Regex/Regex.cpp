// 1. Wczytaj od u¿ytkownika ³añcuch znaków, a nastêpnie sprawdz czy jest to poprawny adres e-mail.

#include <iostream>
#include <regex>
#include <string>
bool checkemail(const std::string& input) {
    std::regex emailregex("^[a-z0-9_.]{3,}@[a-z0-9_]+.(com|pl|edu)$");
    return std::regex_match(input, emailregex);
}

int main()
{
    std::cout << "podaj adres email: " << std::endl;
    std::string input ="";
    std::cin >> input;

    std::cout << "zgodny wynik: " << std::boolalpha << checkemail(input) << std::endl;
   
}

