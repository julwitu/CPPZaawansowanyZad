// a) Wygeneruj 100000 losowych liczb z przdzia³u -100000 100000
//b) zapisz je do pliku
//c) nastepnie wczytaj je z tego pliku do vectora
//d) wypiszcie 100 pierwszych wczytanych liczb(uzycjie std::advance)

#include <iostream>
#include <random>
#include <vector>
#include <fstream>


int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-100000, 100000);

    std::string fileName("C:\\Users\\jwitu\\OneDrive\\Pulpit\\SDA\\CPPZaawansowanyZad\\liczbylosowe.txt");
    std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);
    //a) 
    //b)
    if(!fileToWrite.is_open()) {
        std::cout << "Blad w odczycie pliku!" << std::endl;
    }
    else {
        if (fileToWrite.good()) {
            for (int i = 0; i < 100000; i++) {
                fileToWrite << distrib(gen) << "\n";
            }
        }
        fileToWrite.close();
    }

    //c) 
    //Otworzyæ plik fileName za pomocš ifstream i odczytaæ w pêlti (do napotkania eof) wszystkie dane. 
    //Odczytujemy za pomocš operatora >> do zmiennej tymczasowej, a nastêpnie wo³amy push_back
    std::vector <int> vector;
    std::string fileName2("C:\\Users\\jwitu\\OneDrive\\Pulpit\\SDA\\CPPZaawansowanyZad\\liczbylosowe.txt");
    std::ifstream fileToRead(fileName2);
    
    if (!fileToRead.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
    }
    else {
        std::cout << "Plik zostal wczytany" << std::endl;
    }

   while (fileToRead.good() && !fileToRead.eof()) {
            int tmp;
            fileToRead >> tmp;
            vector.push_back(tmp);
   }
   
   //d) /wypisac 100 pierwszych liczb (uzycjie std::advance)
    //sprawdzmy czy w zapisanym pliku te liczby sa w tej samej kolejnosci
   auto to = vector.begin();
   std::advance(to, 100);
   std::for_each(vector.begin(), to, [](int i) {std::cout << i << " "; });
}

