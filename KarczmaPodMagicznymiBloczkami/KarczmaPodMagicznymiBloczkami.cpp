#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "MenuManager.h"

using namespace std;


//Globalna zmienna uzupe³niana przez funkcjê GetMenu()
extern string Menu[11][5];

int summaryDinnerTab[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
   //tablica zbieraj¹ca iloœæ zamówionych rzeczy po indeksach
int confirm;
void ShowMenu() 
{
    GetMenu("TestMenu.txt");
    cout << "Nasze aktualne menu: \n" << endl;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 5; j++) {
            cout << Menu[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

void ShowDinnerAmountSummary() 
{
    cout << "Tablica zamówionych rzeczy: ";
    for (int k = 0; k < 11; k++) {
        cout << summaryDinnerTab[k];

    }
    cout << endl;
    cout << "\n" << endl;
}                            
//tablica do diagnozowania zamówienia pozycji na poszczególnych indeksach!!!!!!!!! - AKTUALNIE NIGDZIE NIE U¯YWANA  


void SummaryDinnerNameShow()
{
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        if (summaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n iloœæ porcji: " << summaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
            cout << endl;
            cout << "\n" << endl;
        }
    }
    do {
        cout << "Czy potwierdzasz swoje zamówienie? \n";
        cout << "1 - tak \n";
        cout << "2 - nie \n";
        cin >> confirm;
    } while (confirm != 1 && confirm != 2);
}

void DinnerSummaryEdit()
{
    do {
        int dinnerIndex;
        int dinnerPortionIndex;
            cout << "Które danie chcesz edytowaæ? Podaj numer pozycji \n";
            cin >> dinnerIndex;
            if (dinnerIndex < 1 || dinnerIndex > 11)
            {
                do
                {
                    cout << "Niepoprawna pozycja! WprowadŸ numer pozycji ponownie! (1 - 11)\n";
                    cin >> dinnerIndex;
                } while (dinnerIndex < 1 || dinnerIndex>11);
            }
        

        cout << "Podaj now¹ iloœæ porcji \n";
        cin >> dinnerPortionIndex;

        if (dinnerPortionIndex < 0 || dinnerPortionIndex > 5)
        {
            do
            {
                cout << "Niepoprawna iloœæ porcji! WprowadŸ numer porcji ponownie (1 - 5), lub wpisz 0, ¿eby zrezygnowaæ z tej pozycji! \n";
                cin >> dinnerPortionIndex;
            } while (dinnerPortionIndex < 0 || dinnerPortionIndex>5);
        }


        summaryDinnerTab[dinnerIndex - 1] = dinnerPortionIndex;
        cout << "Twoje zamówienie teraz to: \n";
        SummaryDinnerNameShow();
        if (confirm != 1 && confirm != 2) 
        {
            do 
            {
                cout << "Wprowadzono inn¹ liczbê ni¿ 1 lub 2. Czy potwierdzasz swoje zamówienie? 1 = tak, 2 = nie \n";
                cin >> confirm;
            } while (confirm == 1 || confirm == 2);
        }
    } while (confirm == 2);
        cout << "Dobry wybór! \n";
}

void ShowFullVersionMenu() {
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        for(int l = 0; l<5; l++)
        {
            if (summaryDinnerTab[k] != 0)
            {
                cout << " " <<Menu[k][l] << " ";
            }
        }
            cout << endl;
    }
}

void FinalOrderShow() {
    for (int k = 0; k < 11; k++)
    {
        if (summaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n iloœæ porcji: " << summaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
            cout << endl;
            cout << "\n" << endl;
        }
    }
}

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