// 10. Napisz funkcjê, która zwróci wszystkie mo¿liwe permutacje 3 liczb (next_permutation)

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> findPermutations(std::string str) {
    std::vector<std::string>permutations;
    std::sort(str.begin(), str.end());
    do {
        permutations.push_back(str);
    } while (std::next_permutation(str.begin(), str.end()));
    std::for_each(permutations.begin(), permutations.end(), [](std::string s) {std::cout << s << " "; });
    return permutations;
}
int main()
{
    findPermutations("524");
}

