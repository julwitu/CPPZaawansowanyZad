// 9. Napisz funkcj�, kt�ra stworzy wektor przechowuj�cy liczby od 1 do n. Nast�pnie utw�rz dwa wektory. Jeden, kt�rzy b�dzie przechowywa� tylko wielokrotno�ci 2, a drugi tylko wielokrotno�ci 3. Nast�pnie zwr�� vector przechowuj�cy tylko wielokrotno�ci 2 i 3. (remove_copy_if, set_intersection)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
//TODO
std::vector<int> createNumbers(int to) {
    std::vector<int>numbers(to);
    std::iota(numbers.begin(), numbers.end(), 1);
   // std::for_each(numbers.begin(), numbers.end(), [](int i) {std::cout << i << " "; });
    std::vector<int>multiple2;
    std::vector<int>multiple3;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(multiple2), [](int i) {});
    
    std::for_each(multiple2.begin(), multiple2.end(), [](int i) {std::cout << i << " "; });
    return numbers;
}

int main()
{
    createNumbers(24);
}

