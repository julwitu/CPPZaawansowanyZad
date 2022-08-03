// 
//Zad 2.
//Wczytaj plik zdania.csv(Podczas pracy z tym zadaniem NIE NADPISUJ tego pliku).
//Wypisz na konsolê :
//-najd³u¿sze zdanie(najwiêcej s³ów)
//- najd³u¿sze zdanie(najwiêcej liter)
//- najkrotsze zdanie(najmniej s³ów)
//- najkrotsze zdanie(najmniej liter)
//- zlicz wszystkie wyst¹pienia wszystkich s³ów w pliku.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>

int main()
{
    std::ifstream phrases("zdania.csv");
    if (!phrases.is_open()) {
        std::cout << "Nie udalo sie wczytac pliku" << std::endl;
        return -1;
    }
    else {
        std::cout << "Plik zostal wczytany " << std::endl << std::endl;
    }

    std::string str;
    std::vector <std::string> vector;
    while (std::getline(phrases, str)) {
        vector.push_back(str);
    }
    phrases.close();

    //std::for_each(vector.begin(), vector.end(), [](std::string str) {std::cout << str << "\n"; });

    std::vector <int> words;
    std::vector <int> letters;

    auto wordsCounter = [&words, &letters](std::string str) {
        int counterWords = 1; // zakladam, ze wczytujemy linie ktore zawieraja przynajmniej jeden wyraz
        int counterLetters = 0;
        for (auto it = 0; it < str.size(); it++) {
            if (str[it] == ' ') {
                counterWords++;
            }
            else if(str[it] > 64 && str[it] < 91 || str[it]> 96 && str[it]< 123) {
                counterLetters++;
            }
        }
        words.push_back(counterWords);
        letters.push_back(counterLetters);
    };

    std::for_each(vector.begin(), vector.end(), wordsCounter);

    int minWords = std::min_element(words.begin(), words.end())-words.begin();
    int maxWords = std::max_element(words.begin(), words.end())-words.begin();

    int minLetters = std::min_element(letters.begin(), letters.end()) - letters.begin();
    int maxLetters = std::max_element(letters.begin(), letters.end()) - letters.begin();
    
    std::cout << "Wyswietlane tylko pierwsze znalezione zdania odpowiadajace kryteriom mix/max" << std::endl << std::endl;

    std::cout << "Zdanie z najmniejsza iloscia slow: " << vector[minWords] << "// Liczba slow: " << words[minWords] <<  std::endl << std::endl;
    std::cout << "Zdanie z najwieksza iloscia slow: " << vector[maxWords] << "// Liczba slow: " << words[maxWords] << std::endl << std::endl;
  
    std::cout << "Zdanie z najmniejsza iloscia liter: " << vector[minLetters] << "// Liczba liter: " << letters[minLetters] << std::endl << std::endl;
    std::cout << "Zdanie z najwieksza iloscia liter: " << vector[maxLetters] << "// Liczba liter: " << letters[maxLetters] << std::endl << std::endl;

    std::cout << "Calkowita liczba slow w pliku: " << std::accumulate(words.begin(), words.end(), 0);
}

//Wypisz na konsolê :
//-najd³u¿sze zdanie(najwiêcej s³ów)
//- najd³u¿sze zdanie(najwiêcej liter)
//- najkrotsze zdanie(najmniej s³ów)
//- najkrotsze zdanie(najmniej liter)
//- zlicz wszystkie wyst¹pienia wszystkich s³ów w pliku.

