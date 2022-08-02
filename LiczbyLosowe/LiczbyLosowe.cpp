//Utw�rz wektor 100 losowych liczb z przedzia�u 0 10, nast�pnie:
//a) wypisz ten wektor
//b) zlicz ilo�� wyst�pie� liczby 5
//c) Wylicz �rednia warto��
//d) Zr�b to samo dla innego rozk�adu warto�ci
#include <iostream>
#include <vector>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
void printVector(unsigned int i) {
    std::cout << i << " ";
}
int main()
{
    //uniform distribution
    std::vector <int> vector(100);
    for (auto it = vector.begin(); it != vector.end(); it++) {
        std::random_device randomDevice;
        std::default_random_engine randomEngine(randomDevice());
        std::uniform_int_distribution<int> dist(0, 10);
        *it = (dist(randomEngine));
    }
    //a)
    std::for_each(vector.begin(), vector.end(), printVector);
    std::cout << std::endl;

    //b)
    auto counter = std::count(vector.begin(), vector.end(), 0);
    std::cout << "Liczba 5 wystepuje " << counter << " razy" << std::endl;

    //c)
    auto avrg = (std::accumulate(vector.begin(), vector.end(), 0))/ static_cast<double>(vector.size());
    std::cout << "srednia: " << avrg << std::endl << std::endl;

    //d) normal distribution
  
}


