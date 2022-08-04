// 7. Napisz funkcjê, która stworzy wektor przechowuj¹cy potêgi kwadratowe z podanego zakresu np od. 3 do 10 (for_each)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> squared(int from, int to) {
    std::vector <int> bases((to-from)+1);
    std::iota(bases.begin(), bases.end(), from);
    std::vector<int>squares;
    auto createSquare = [&squares](int i) {
        squares.push_back(i * i);
    };
    std::for_each(bases.begin(), bases.end(), createSquare);
    //std::for_each(squares.begin(), squares.end(), [](int i) {std::cout << i << " "; });
    return squares;
}

int main()
{
    squared(3, 10);

}
