// Zad 1.
//Program lista zakup�w
//Stw�rz program, kt�ry b�dzie od u�ytkownika wczytywa� nazwy produkt�w spo�ywczych oraz ilo�� do kupienia(dla uproszczenia bez jednostki miary).
//- dla pewno�ci zamie� du�e litery na ma�e
//- gdy uzytkownik poraz drugi wprowadzi ten sam produkt, zapytaj si� go co chce zrobi� :
//a) nadpisac(zamieniamy star� warto�� na now�)
//b) zsumowac(sumujemy obie warto�ci)
//c) pominac(zostawiamy pierwsz� warto��)
//
//Nast�pnie zapisz dane do pliku lista_zakupow.txt
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
