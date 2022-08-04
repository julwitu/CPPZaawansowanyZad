// 9. Napisz funkcjê, która stworzy wektor przechowuj¹cy liczby od 1 do n. Nastêpnie utwórz dwa wektory. Jeden, którzy bêdzie przechowywa³ tylko wielokrotnoœci 2, a drugi tylko wielokrotnoœci 3. Nastêpnie zwróæ vector przechowuj¹cy tylko wielokrotnoœci 2 i 3. (remove_copy_if, set_intersection)

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
   std::for_each(numbers.begin(), numbers.end(), [&multiple2](int i) {
        if (i % 2 == 0) {
            multiple2.push_back(i);
        }
        });
    std::for_each(numbers.begin(), numbers.end(), [&multiple3](int i) {
        if (i % 3 == 0) {
            multiple3.push_back(i);
        }
        });
    //TODO remove_copy_if

    std::vector<int>multiple2and3;
    // znajduje elementy powtarzajace sie w obu wektorach i wypycha je do nowego wektora
    std::set_intersection(multiple2.begin(), multiple2.end(), 
        multiple3.begin(), multiple3.end(),
        std::back_inserter(multiple2and3));

    std::for_each(multiple2and3.begin(), multiple2and3.end(), [](int i) {std::cout << i << " "; });
    return multiple2and3;
}

int main()
{
    createNumbers(24);
}

