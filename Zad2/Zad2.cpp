// 2. Napisz analogiczn¹ funkcjê, która zwróci przemieszanego stringa (random_shuffle). Zwróæ uwagê czy za ka¿dym uruchomieniem, faktycznie string jest przemieszany innaczej

#include <iostream>
#include <string>
#include <algorithm>

void randomShuffle(std::string& str) {
    std::random_shuffle(str.begin(), str.end());
}

std::string randomShuffleAndCreateNew(const std::string& str) {
    std::string newStr;
    std::copy(str.begin(), str.end(), std::back_inserter(newStr));
    std::random_shuffle(newStr.begin(), newStr.end());
    return newStr;
}
int main()
{
    std::string str1 = "Hello World!";
    std::string str2 = "Goodbye World";
    randomShuffle(str1);
    std::cout << str1 << std::endl;
    std::cout << randomShuffleAndCreateNew(str2) << std::endl;
    randomShuffle(str1);
    std::cout << str1 << std::endl;
   

}