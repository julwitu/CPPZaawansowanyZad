// Zad 1.
//Program lista zakupów
//Stwórz program, który bêdzie od u¿ytkownika wczytywa³ nazwy produktów spo¿ywczych oraz iloœæ do kupienia(dla uproszczenia bez jednostki miary).
//- dla pewnoœci zamieñ du¿e litery na ma³e
//- gdy uzytkownik poraz drugi wprowadzi ten sam produkt, zapytaj siê go co chce zrobiæ :
//a) nadpisac(zamieniamy star¹ wartoœæ na now¹)
//b) zsumowac(sumujemy obie wartoœci)
//c) pominac(zostawiamy pierwsz¹ wartoœæ)
//
//Nastêpnie zapisz dane do pliku lista_zakupow.txt
//np :
//jablko 4
//ziemniaki 3
//kiszony ogorek 1
//smietana 1
#include <iostream>
#include <string>
#include <map>
void mapInserter(std::map <std::string, int>& map) {
    std::string product;
    int amount;
    std::cout << "Podaj nazwe productu : " << std::endl;
    std::getline(std::cin, product);
    std::cout << "Podaj ilosc : " << std::endl;
    std::cin >> amount;
    if (map.find(product) != map.end()) {
        std::cout << "Product juz istnieje. Dodaj wiecej (Y) czy nadpisz (N)" << std::endl;
        char c;
        std::cin >> c;
        if (c == 'Y') {

        }
    }
    else {
        map.insert({ product, amount });
    }
}
int main()
{
    std::map <std::string, int> shoppingList;
 

}
