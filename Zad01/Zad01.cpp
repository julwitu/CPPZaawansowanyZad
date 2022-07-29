//Zad 0.1 Lambda
//Napisz zwyk³¹ funkcj¹ oraz lambdê(przypisz j¹ do zmiennej) Nastêpnie je wywo³aj :
//a) funkcj¹ wypisuj¹ca “Hello World”
//b) Funkcja dodaj¹ca dwie liczby do siebie(i zwracaj¹ca j¹)

#include <iostream>
void sayHello() {
    std::cout << "Hello World" << std::endl;
}

int addTwoNumbers(int a, int b) {
    return a + b;
}


int main()
{
    auto sayHelloLambda = []() {
        std::cout << "Hello World" << std::endl;
    };

    auto addTwoNumbersLambda = [](int a, int b) {
        return a + b;
    };
    sayHelloLambda();
    std::cout << addTwoNumbersLambda(5, 6) << std::endl;
}


