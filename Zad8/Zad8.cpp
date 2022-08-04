// 8. Zmieñ poprzednie zadanie tak aby zwraca³o sumê kwadratów (accumulate)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int squaredAcc(int from, int to) {
    std::vector <int> bases((to - from) + 1);
    std::iota(bases.begin(), bases.end(), from);
    std::vector<int>squares;
    auto createSquare = [&squares](int i) {
        squares.push_back(i * i);
    };
    std::for_each(bases.begin(), bases.end(), createSquare);
    return std::accumulate(squares.begin(), squares.end(), 0);
}
int main()
{
    std::cout << squaredAcc(1, 3);
}

