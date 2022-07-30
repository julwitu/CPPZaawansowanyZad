// Zad 0.3
//Utwórz wektor liczb ca³kowitych od - 100 do 100.
//a) Nastêpnie sprawdŸ czy wszystkie liczby s¹ dodatnie.
//b) Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30.
//c) Usuñ z kontenera 0.
//d) Nastêpnie sprawdŸ czy kontener nie zawiera wartoœci 0.
//e) SprawdŸ czy kontener jest posortowany
//f) Skopiuj do drugiego wektora wszystkie liczby wiêksze od 90 i mniejsze od - 90
//g) Skopiuj do innego wektora 10 kolejnych liczb zaczynaj¹c od 78

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> numbers(201);
    std::iota(numbers.begin(), numbers.end(), -100);

    std::cout << "Print vector: ";
    std::for_each(numbers.begin(), numbers.end(), [](int i) {std::cout << i << " "; });
    std::cout << std::endl << std::endl;
    //a) Nastêpnie sprawdŸ czy wszystkie liczby s¹ dodatnie.
    std::cout << "Czy wszystkie liczby sa dodatnie: ";
    std::cout << std::boolalpha << std::all_of(numbers.begin(), numbers.end(), [](int i) {return i > 0; });
    std::cout << std::endl << std::endl;

    //b) Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30.
    std::cout << "Czy jakakolwiek liczba jest podzielna przez 3, 5 i 30: ";
    auto dividesByNumbers = [](int i) {
        if (i % 3 == 0 && i % 5 == 0 && i % 30 == 0) {
            return i;
        }
    };
    std::cout << std::any_of(numbers.begin(), numbers.end(), dividesByNumbers);
    std::cout << std::endl << std::endl;

    //c) Usuñ z kontenera 0.
    auto it = std::remove(numbers.begin(), numbers.end(), 0); 
    numbers.erase(it, numbers.end());
    std::cout << "After removing 0: ";
    std::for_each(numbers.begin(), numbers.end(), [](int i) {std::cout << i << " "; });   
    std::cout << std::endl << std::endl;
    //d) Nastêpnie sprawdŸ czy kontener nie zawiera wartoœci 0.
    std::cout << "Contains 0? ";

    auto result = std::find(numbers.begin(), numbers.end(), 0);
    if (result != numbers.end()) {
        std::cout << "Yes";
    }
    else {
        std::cout << "Not found";
    }
    std::cout << std::endl << std::endl;

    //e) SprawdŸ czy kontener jest posortowany
    std::cout << "Czy kontener jest posortowany? ";
    std::cout << std::is_sorted(numbers.begin(), numbers.end());
    std::cout << std::endl << std::endl;

    //f) Skopiuj do drugiego wektora wszystkie liczby wiêksze od 90 i mniejsze od - 90
    std::vector <int> vector;
   std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(vector),[](int i) {return i < -90 || i> 90; });
    
    std::cout << "Print vector 2: ";
    std::for_each(vector.begin(), vector.end(), [](int i) {std::cout << i << " "; });
    std::cout << std::endl << std::endl;

    //g) Skopiuj do innego wektora 10 kolejnych liczb zaczynaj¹c od 78
    std::vector <int> vector2;
    auto copyFrom = std::find(numbers.begin(), numbers.end(), 78);
    auto copyTo = copyFrom + 10;
    std::copy(copyFrom, copyTo, std::back_inserter(vector2));


    std::cout << "Print vector 3: ";
    std::for_each(vector2.begin(), vector2.end(), [](int i) {std::cout << i << " "; });
    std::cout << std::endl << std::endl;
}
