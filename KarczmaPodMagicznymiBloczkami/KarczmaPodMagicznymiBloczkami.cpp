#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <locale.h>
#include "MenuManager.h"

using namespace std;

bool ExitProgram;
//Globalna zmienna uzupe³niana przez funkcjê GetMenu()
extern string Menu[11][5];

int main()
{
    ShowMenu();

    int orderSize, dinnerNum, i, dinnerAmount, dinnerSummary, fullVersionMenu;
    cout << "Ile ³acznie pozycji z menu chcai³byœ zamóiæ? Wybierz, wpisuj¹c cyfrê z zakresu 1-11 " << endl;    //Zapytanie o ³¹czn¹ iloœæ porcji
    cin >> orderSize;
    if (orderSize < 1 || orderSize > 11)
    {
        do
        {
            cout << "\n Maksymalna ilosc pozycji w naszym menu wynosi 11! Wybierz wartoœæ pomiêdzy 1 a 11!\n";
            cin >> orderSize;
        } while (orderSize < 1 || orderSize>11);
    }

    cout << "Wybierz zatem interesuj¹ce Ciebie pozycje \n";
    int j = 1;
    for (i = 0; i < orderSize; i++)
    {
        cout << "Podaj numer swojej " << j << " pozycji dania z menu (1 - 11) \n";        //wprowadzanie konkretnych pozycji z menuu do tablicy
        cin >> dinnerNum;

        j += 1;
        if (dinnerNum < 1 || dinnerNum > 11)
        {
            do
            {
                cout << "Niepoprawna pozycja! WprowadŸ numer pozycji ponownie! (1 - 11)\n";
                cin >> dinnerNum;
            } while (dinnerNum < 1 || dinnerNum>11);
            dinnerSummary = dinnerNum;
            dinnerSummary = summaryDinnerTab[i];
        }

        cout << "Podaj iloœæ porcji z aktualnie wybranej pozycji. Maksymalnie mozesz maksymalnie zamowic 5 porcji kazdej z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
        cin >> dinnerAmount;
        cout << " \n";
        if (dinnerAmount < 1 || dinnerAmount>5)
        {
            cout << "Niepoprawna iloœæ porcji! wybierz iloœæ porcji ponownie! \n";
            do
            {
                cout << "Podaj iloœæ porcji z aktualnie wybranej pozycji. Maksymalnie mo¿esz zamówiæ 5 porcji ka¿dej z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
                cin >> dinnerAmount;
            } while (dinnerAmount < 1 || dinnerAmount > 5);
        }
        summaryDinnerTab[dinnerNum - 1] = dinnerAmount;
    }

    //Podsumowanie

    SummaryDinnerNameShow();
    
    if (confirm == 2)
    {
        DinnerSummaryEdit();
    }
    else
    {
        cout << "Dobry wybór! \n\n\n";
    }
    cout << "Twoje finalne zamówienie, to: " << endl;
    FinalOrderShow();
    cout << "Czy chcesz wyœwietliæ wersjê pe³n¹ wybranych pozycji? 1 - tak, 2 - nie\n" << endl;
    cin >> fullVersionMenu;
    if (fullVersionMenu == 1) 
    {
        ShowFullVersionMenu();
    }


    return 0;
}