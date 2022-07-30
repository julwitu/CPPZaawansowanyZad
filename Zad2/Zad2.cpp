//2. Napisz analogiczn¹ funkcjê, która zwróci przemieszanego stringa (random_shuffle). Zwróæ uwagê czy za ka¿dym uruchomieniem, faktycznie string jest przemieszany innaczej
#include <string>
#include <algorithm>
#include <iostream>
std::string shuffleString(std::string str) {
    std::random_shuffle(str.begin(), str.end());
    return str;
}
int main()
{
    std::string str = "abcdefghijkl";
    std::cout << shuffleString(str) << std::endl;
    std::cout << shuffleString(str) << std::endl;
    std::cout << shuffleString(str) << std::endl;
    std::cout << shuffleString(str) << std::endl;
}


