#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <locale.h>
#include "MenuManager.h"

using namespace std;

bool ExitProgram;
//Globalna zmienna uzupe�niana przez funkcj� GetMenu()
extern string Menu[11][5];

int summaryDinnerTab[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
   //tablica zbieraj�ca ilo�� zam�wionych rzeczy po indeksach
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
    cout << "Tablica zam�wionych rzeczy: ";
    for (int k = 0; k < 11; k++) {
        cout << summaryDinnerTab[k];

    }
    cout << endl;
    cout << "\n" << endl;
}                            
//tablica do diagnozowania zam�wienia pozycji na poszczeg�lnych indeksach!!!!!!!!! - AKTUALNIE NIGDZIE NIE U�YWANA  


void SummaryDinnerNameShow()
{
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        if (summaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n ilo�� porcji: " << summaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
            cout << endl;
            cout << "\n" << endl;
        }
    }
    do {
        cout << "Czy potwierdzasz swoje zam�wienie? \n";
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
            cout << "Kt�re danie chcesz edytowa�? Podaj numer pozycji \n";
            cin >> dinnerIndex;
            if (dinnerIndex < 1 || dinnerIndex > 11)
            {
                do
                {
                    cout << "Niepoprawna pozycja! Wprowad� numer pozycji ponownie! (1 - 11)\n";
                    cin >> dinnerIndex;
                } while (dinnerIndex < 1 || dinnerIndex>11);
            }
        

        cout << "Podaj now� ilo�� porcji \n";
        cin >> dinnerPortionIndex;

        if (dinnerPortionIndex < 0 || dinnerPortionIndex > 5)
        {
            do
            {
                cout << "Niepoprawna ilo�� porcji! Wprowad� numer porcji ponownie (1 - 5), lub wpisz 0, �eby zrezygnowa� z tej pozycji! \n";
                cin >> dinnerPortionIndex;
            } while (dinnerPortionIndex < 0 || dinnerPortionIndex>5);
        }


        summaryDinnerTab[dinnerIndex - 1] = dinnerPortionIndex;
        cout << "Twoje zam�wienie teraz to: \n";
        SummaryDinnerNameShow();
        if (confirm != 1 && confirm != 2) 
        {
            do 
            {
                cout << "Wprowadzono inn� liczb� ni� 1 lub 2. Czy potwierdzasz swoje zam�wienie? 1 = tak, 2 = nie \n";
                cin >> confirm;
            } while (confirm == 1 || confirm == 2);
        }
    } while (confirm == 2);
        cout << "Dobry wyb�r! \n";
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
            cout << Menu[k][1] << "\n ilo�� porcji: " << summaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
            cout << endl;
            cout << "\n" << endl;
        }
    }
}

int main()
{

    return 0;
}