// Zad6. Napisz funkcjê, która sprawdzi czy podany string jest palindromem (reverse i transform lub equal)

#include <iostream>
#include <string>
#include <algorithm>
bool isPalindrom(const std::string& str) {
    std::string newStr;
    std::copy(str.rbegin(), str.rend(), std::back_inserter(newStr));
    return newStr == str;
}

int main()
{
    std::string str1 = "niepalindrom";
    std::string str2 = "kajak";
    std::cout << "Is palindrom? " << isPalindrom(str1) << std::endl;
    std::cout << "Is palindrom? " << isPalindrom(str2) << std::endl;
}


