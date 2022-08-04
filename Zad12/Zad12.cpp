// 12. Napisz funkcjê, która zamieni podanego int na vector jej cyfr. 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> changeIntToVector(int i) {
    //TODO rozwiazac iterujac po str;
   // std::string newStr = std::to_string(i);
    //for (int i = 0; i<newStr.size(); ++i) {
    //    digits.push_back(newInt??);
    //}
    std::vector<int>digits;
    while (i != 0) {
        digits.push_back(i % 10);
        i /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    std::for_each(digits.begin(), digits.end(), [](int num) {std::cout << num << " "; });
    return digits;
}

int main()
{
    changeIntToVector(41587223);
   
}

