// 11. Napisz funkcjê, która przyjmuje wektor cyfr, a zwraca liczbê permutacji tych cyfr, które s¹ wielokrotnoœci¹ 11.
// TODO Ulepszyc 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
std::vector<int> findPermutation(std::vector<int>&digits) {
    std::vector<std::string>allPermutations;
    std::vector <int> permutationsInt;
    std::string temp;
    //konwersja wektora intow na str, zrobienie permutacji i wypchniecie ich do wektora str
    for (auto it = digits.begin(); it != digits.end(); it++) {
        temp += std::to_string(*it);
    }
    do {
        allPermutations.push_back(temp);
    } while (std::next_permutation(temp.begin(), temp.end()));
    // konwersja calego wektora str na int i wypchniecie ich do nowego wektora
    std::for_each(allPermutations.begin(), allPermutations.end(), [&permutationsInt](std::string s) {
        permutationsInt.push_back(std::stoi(s)); });
// Wypchniecie ostatecznych wynikow do nowego wektora
    std::vector<int>final;
    for (auto it = permutationsInt.begin(); it != permutationsInt.end(); it++) {
        if ((*it) % 11 == 0) {
            final.push_back(*it);
        }
    }
    return final;
}
int main()
{
    std::vector<int> numbers = { 2, 5, 9, 1 };
    std::vector<int>newVector = findPermutation(numbers);
    std::for_each(newVector.begin(), newVector.end(), [](int i) {std::cout << i << " "; });
}

