// 1. Napisz funkcjê, która przyjmuje stringa, nastêpnie uszereguje wszystkie litery w porz¹dku alfabetycznym i zwraca tak odwróconego stringa (sort).

#include <iostream>
#include <string>
#include <algorithm>

void stringReverse(std::string& str) {
    std::sort(str.begin(), str.end());
}

std::string reverseAndCreateNew(const std::string& str) {
    std::string newStr;
    std::copy(str.begin(), str.end(), std::back_inserter(newStr));
    std::sort(newStr.begin(), newStr.end());
    return newStr;
}
int main()
{
    std::string str1 =  "Hello World!";
    std::string str2 = "Goodbye World";
   stringReverse(str1);
   std::cout << str1 << std::endl;
   std::cout << reverseAndCreateNew(str2);

}
