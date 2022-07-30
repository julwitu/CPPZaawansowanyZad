// 1. Napisz funkcjê, która przyjmuje stringa, nastêpnie uszereguje wszystkie litery w porz¹dku alfabetycznym i zwraca tak 
//odwróconego stringa (sort).
#include <string>
#include <algorithm>
#include <iostream>

//zwraca wg tablicy ascii najpierw znaki, pozniej duze i male litery
std::string strSortAscii(std::string str) {
    std::sort(str.begin(), str.end(), std::less<int>());
    return str;
}

int main()
{
    std::string str = "aAdhavdQ!$gafPPRuc";
    std::cout << strSortAscii(str);
}

