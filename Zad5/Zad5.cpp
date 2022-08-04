// 5. Napisz funkcjê, która zliczy wyst¹pienia podanej litery w podanym stringu (count).

#include <iostream>
#include <string>
#include <algorithm>

int counter(std::string str, char c) {
   return std::count(str.begin(), str.end(), c);
}
int main()
{
    std::string str = "ala ma kota kot ma ale siema siema";

    std::cout << counter(str, 'k');

}

