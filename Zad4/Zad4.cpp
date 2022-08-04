// 4. Napisz funkcjê, która usunie spacje z podanego stringa.(remove i erase) 

#include <iostream>
#include <string>
#include <algorithm>

void removeWhiteSpaces(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}
int main()
{
    std::string str = "Hello World And Goodbye World";
    removeWhiteSpaces(str);
    std::cout << str;

}

