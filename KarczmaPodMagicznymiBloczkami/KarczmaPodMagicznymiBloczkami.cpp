#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "MenuManager.h"


using namespace std;

//Globalna zmienna uzupe³niana przez funkcjê GetMenu()
extern string Menu[11][5];

void ShowMenu() {
    GetMenu("TestMenu.txt");
    cout << "Nasze aktualne menu: \n" << endl;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 5; j++) {
            cout << Menu[i][j] << " ";
        }
        cout  << endl;
    }
    cout << "\n" << endl;
}


int main()
{
    ShowMenu();
    int OrderSize;
    cout << "Ile lacznie pozycji chcialbys zamowic? Wybierz, wpisujac cyfre z zakresu 1-11 " << endl;
    cin >> OrderSize;
    if (OrderSize < 1 || OrderSize > 11) {
        cout << "\n Maksymalna ilosc pozycji w naszym menu, wynosi 11! Wybierz wartosc pomiedzy 1 a 11!\n";
    }
    else {
        cout << "\n git";
        //odt¹d lecê dalej z kodem
    }

    return 0;
}