//Zad 0.1 Lambda
//Napisz zwyk�� funkcj� oraz lambd�(przypisz j� do zmiennej) Nast�pnie je wywo�aj :
//a) funkcj� wypisuj�ca �Hello World�
//b) Funkcja dodaj�ca dwie liczby do siebie(i zwracaj�ca j�)

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


