// Zad 0.2
//Stwórz wektor 100 kolejnych liczb ca³kowitych z zakresu od 1 do 100
//a) Wypisz wszystkie liczby(for_each + unary function)
//b) Wypisz wszystkie liczby mniejsze od 50 (for_each + funktor)
//c) Nastêpnie policz ile jest liczb wiêkszych ni¿ 4 (count_if + predykat)
//d) Zrób to samo dla a, b i c, ale wykorzystaj lambdê
//e) W zale¿noœci od zmiennej lokalnej dzielnik wypisz wszystkie liczby podzielne przez
//niego(for_each + lambda
//    f) Zlicz sumê wszystkich liczb parzystych i zapisz j¹ do zmiennej lokalnej int sum;

#include <iostream>
#include <vector>
#include <algorithm>
void printNumbers(unsigned int i) {
    std::cout << i << " ";
}
struct lessThan50 {
    void operator()() {
        if (_value < 50) {
            std::cout << _value;
        }
    }
    int _value;
};

bool moreThan4(int i) {
    if(i > 4) {
        return 1;
   }
    return 0;
}

int main()
{
    std::vector <unsigned int> numbers(100);

    for (size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = i + 1;
    }
    // inne rozwiazanie
    // musi byc dodana include numeric
    // std::iota(numbers.begin(), numbers.end(), 1);
    std::cout << "Zad a, b, c" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), printNumbers);
    std::cout << std::endl << std::endl;

    
    std::for_each(numbers.begin(), numbers.end(), lessThan50());
    std::cout << std::endl << std::endl;

    int moreThan4Counter = std::count_if(numbers.begin(), numbers.end(), moreThan4);
    std::cout << "Liczby wieksze niz 4: " << moreThan4Counter << std::endl;

    std::cout << "Lambdas Lambdas Lambdas Lambdas Lambdas" << std::endl;
    auto printVector = [](int i) {
        std::cout << i << " ";
    };
    std::for_each(numbers.begin(), numbers.end(), printVector);
    std::cout << std::endl << std::endl;


    auto moreThan4Lambda = [](int i) {
        if (i > 4) {
            return 1;
        }
        return 0;
    };
    int moreThan4Counter2 = std::count_if(numbers.begin(), numbers.end(), moreThan4Lambda);
    std::cout << "Liczby wieksze niz 4: " << moreThan4Counter2 << std::endl;


    std::cout << "Dzielnik liczby" << std::endl;
    auto dividesBy = [numbers](int i) {
        int divider = 5;
        if (numbers[i-1] % divider == 0) {
            std::cout << numbers[i-1] << std::endl;
        }
    };
    std::for_each(numbers.begin(), numbers.end(), dividesBy);

    //    f) Zlicz sumê wszystkich liczb parzystych i zapisz j¹ do zmiennej lokalnej int sum;
 //   std::cout << "Licznik parzystych " << std::endl;
 //   auto evenCount= [&numbers](int i) {
 //       if (numbers[i-1] % 2 == 0) {
 //           return 1;
 //       }
 //       return 0;
 //   };
 //int evenCounter = std::count(numbers.begin(), numbers.end(), evenCount);
 //std::cout << "Liczby parzyste: " << evenCounter << std::endl;
}

