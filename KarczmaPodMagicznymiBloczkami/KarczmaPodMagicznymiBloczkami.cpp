#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <locale.h>
#include <time.h>
#include "MenuManager.h"

using namespace std;

bool ExitProgram;
//Globalna zmienna uzupe�niana przez funkcj� GetMenu()
extern string Menu[11][5];
extern int SummaryDinnerTab[11];
class UserName
{
public: string userFirstName;
public: string userSurname;
};
class UserAddress
{
public: string streetName;
public: string streetNumber;
public: string cityName;
};
UserAddress SetAddress()
{
    UserAddress userAddress;
    cout << "Podaj nazw� ulicy: ";
    cin >> userAddress.streetName;
    cout << "Podaj numer domu: ";
    cin >> userAddress.streetNumber;
    cout << "Podaj nazw� miejscowo�ci: ";
    cin >> userAddress.cityName;
    return userAddress;
}
int SetTableNumber()
{
    srand(time(0));
    int tableNumber;
    tableNumber = 1 + (rand() % 99);
    return tableNumber;
}
void DisplayRestaurantName()
{
    cout << "******************************************" << endl;
    cout << "Witamy w Karczmie Pod Magicznymi Bloczkami" << endl;
    cout << "******************************************" << endl;
    cout << "Pod Magicznymi Bloczkami" << endl;
    cout << "Adres: Collegium Da Vinci" << endl;
    cout << "W�a�ciciel: Ged, zwany Kroulcem" << endl;
    cout << "Godziny otwarcia: 10:00-20:00" << endl;
    cout << "******************************************" << endl;
}

int main()
{
    setlocale(LC_ALL, "polish");
    ExitProgram = false;
    UserName userName;
    UserAddress userAddress;
    int selectOption = 0;
    while (ExitProgram != true)
    {
        ExitProgram = false;
        DisplayRestaurantName();
        cout << "Podaj swoje imi�: ";
        cin >> userName.userFirstName;
        cout << "Podaj swoje nazwisko: ";
        cin >> userName.userSurname;
        cout << "Witamy " << userName.userFirstName << " " << userName.userSurname << '!' << endl;
        cout << "Wybierz co chcesz zrobi�, wpisuj�c odpowiedni� cyfre" << endl;
        cout << "1. Jedzenie na miejscu" << endl;
        cout << "2. Jedzenie na wynos" << endl;
        cout << "3. Zacznij od nowa" << endl;
        cout << "4. Opu�� program" << endl;
        cin >> selectOption;
        bool correctHour = false;
        switch (selectOption)
        {
        case 1: 
            int setTableNumber;
            setTableNumber = SetTableNumber();
            cout << "Zapraszamy do stolika: " << setTableNumber << endl;
            break;
        case 2:
            userAddress = SetAddress();
            cout << "Zam�wienia mog� by� otrzymywane w godzinach od 11 do 20" << endl;
            cout << "Podaj preferowan� godzin� otrzymania zam�wienia: ";
            while (correctHour != true)
            {
                int setOrderHour;
                cin >> setOrderHour;
                if (setOrderHour < 11 || setOrderHour > 20)
                {
                    cout << "Nieprwid�owa godzina! Przypominamy �e zam�wienia na dow�z s� realizowane w godzinach od 11 do 20." << endl;
                    correctHour = false;
                }
                else
                    correctHour = true;
            }
            break;
        case 3:
            system("cls");
            break;
        case 4:
            ExitProgram = true;
            break;
        default:
            system("cls");
            cout << "Podaj inn� liczb�!" << endl;
            continue;
        }
        if (selectOption == 3 || selectOption == 4 || correctHour == false)
            continue;
        cout << "Wybierz co chcesz zrobi�, wpisuj�c odpowiedni� cyfre" << endl;
        cout << "1. Zobacz menu i z�� zam�wienie" << endl;
        cout << "2. Zacznij od nowa" << endl;
        cout << "3. Wy��cz aplikacje" << endl;
        cin >> selectOption;
        if (selectOption == 1)
        {
            system("cls");
            DisplayRestaurantName();
            ShowMenu();

            int orderSize, dinnerNum, i, dinnerAmount, fullVersionMenu;
            cout << "Ile �acznie pozycji z menu chcai�by� zam�i�? Wybierz, wpisuj�c cyfr� z zakresu 1-11 \n";    //Zapytanie o ��czn� ilo�� porcji
            cin >> orderSize;
            if (orderSize < 1 || orderSize > 11)
            {
                do
                {
                    cout << "\n\n Maksymalna ilosc pozycji w naszym menu wynosi 11! Wybierz warto�� pomi�dzy 1 a 11!\n";
                    cin >> orderSize;
                } while (orderSize < 1 || orderSize>11);
            }

            cout << "\n\nWybierz zatem interesuj�ce Ciebie pozycje \n";
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
                        cout << "\nNiepoprawna pozycja! Wprowad� numer pozycji ponownie! (1 - 11)\n";
                        cin >> dinnerNum;
                    } while (dinnerNum < 1 || dinnerNum>11);
                }

                cout << "\nPodaj ilo�� porcji z aktualnie wybranej pozycji. Maksymalnie mozesz maksymalnie zamowic 5 porcji kazdej z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
                cin >> dinnerAmount;
                cout << " \n\n";
                if (dinnerAmount < 1 || dinnerAmount>5)
                {
                    cout << "Niepoprawna ilo�� porcji! wybierz ilo�� porcji ponownie! \n";
                    do
                    {
                        cout << "Podaj ilo�� porcji z aktualnie wybranej pozycji. Maksymalnie mo�esz zam�wi� 5 porcji ka�dej z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
                        cin >> dinnerAmount;
                    } while (dinnerAmount < 1 || dinnerAmount > 5);
                }
                SummaryDinnerTab[dinnerNum - 1] = dinnerAmount;
            }

            //Podsumowanie

            SummaryDinnerNameShow();

            cout << "Twoje finalne zam�wienie, to: \n\n\n\n";
            FinalOrderShow();
            cout << "Czy chcesz wy�wietli� wersj� pe�n� wybranych pozycji? 1 - tak, 2 - nie\n";
            cin >> fullVersionMenu;
            if (fullVersionMenu == 1)
            {
                ShowFullVersionMenu();
            }
            ExitProgram = true;
            continue;

        }
        else if (selectOption == 2)
        {
            system("cls");
            continue;
        }
        else if (selectOption == 3)
        {
            ExitProgram = true;
            break;
        }
        else
            system("cls");
            cout << "Podaj inn� liczb�!" << endl;;
            continue;
    }

    return 0;
}