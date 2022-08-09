// 13. Napisz funkcjê, która znajdzie pierwsz¹ wiêksz¹ liczbê, która jest palindromem od zadanej liczby.

#include <iostream>
#include <string>
#include <algorithm>
int findNextPalindrom(int i) {
    bool isPalindrom = false;
    std::string result;
    do {
        i++;
        std::string temp = std::to_string(i);
        std::string numberReversed;
        std::copy(temp.rbegin(), temp.rend(), std::back_inserter(numberReversed));
        if (numberReversed == temp) {
            isPalindrom = true;
            result = numberReversed;
        }
    } while (!isPalindrom);
    return std::stoi(result);
}

int main()
{
    std::cout << findNextPalindrom(300) << std::endl;
    std::cout << findNextPalindrom(515);
}

