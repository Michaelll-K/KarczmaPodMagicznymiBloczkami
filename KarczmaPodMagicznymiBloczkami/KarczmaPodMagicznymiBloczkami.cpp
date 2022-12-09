#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <locale.h>
#include <time.h>
#include "MenuManager.h"
#include "UserManager.h"

using namespace std;

bool ExitProgram;
//Globalna zmienna uzupe³niana przez funkcjê GetMenu()
extern string Menu[11][5];
//Globalna zmienna przechowuj¹ca zamówienie u¿ytkownika
extern int SummaryDinnerTab[11];
//Globalna zmienna przechowuj¹ca sk³adniki dañ klienta
extern string UserDishesDetails[5][2];

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
    cout << "Podaj nazwê ulicy: ";
    cin >> userAddress.streetName;
    cout << "Podaj numer domu: ";
    cin >> userAddress.streetNumber;
    cout << "Podaj nazwê miejscowoœci: ";
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
    cout << "W³aœciciel: Ged, zwany Krogulcem" << endl;
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
        system("cls");
        ExitProgram = false;
        DisplayRestaurantName();
        cout << "Podaj swoje imiê: ";
        cin >> userName.userFirstName;
        cout << "Podaj swoje nazwisko: ";
        cin >> userName.userSurname;
        cout << "Witamy " << userName.userFirstName << " " << userName.userSurname << '!' << endl;
        cout << "Wybierz co chcesz zrobiæ, wpisuj¹c odpowiedni¹ cyfrê" << endl;
        cout << "1. Jedzenie na miejscu" << endl;
        cout << "2. Dostawa na wskazany adres" << endl;
        cout << "3. Zacznij od nowa" << endl;
        cout << "4. WyjdŸ z aplikacji" << endl;
        cin >> selectOption;
        switch (selectOption)
        {
        case 1: 
            int setTableNumber;
            setTableNumber = SetTableNumber();
            cout << "Zapraszamy do stolika: " << setTableNumber << endl;
            break;
        case 2:
            userAddress = SetAddress();
            break;
        case 3:
            system("cls");
            break;
        case 4:
            ExitProgram = true;
            break;
        default:
            system("cls");
            cout << "Podaj inn¹ liczbê!" << endl;
            continue;
        }
        if (selectOption == 3 || selectOption == 4)
            continue;

        cout << "Wybierz co chcesz zrobiæ, wpisuj¹c odpowiedni¹ cyfrê" << endl;
        cout << "1. Zobacz menu i z³ó¿ zamówienie" << endl;
        cout << "2. Zacznij od nowa" << endl;
        cout << "3. WyjdŸ z aplikacji" << endl;
        cin >> selectOption;

        if (selectOption == 1)
        {
            system("cls");
            DisplayRestaurantName();
            ShowMenu();

            
            int orderSize, dinnerNum, i, dinnerAmount, fullVersionMenu;
            cout << "Ile ³¹cznie pozycji z menu chcesz zamówiæ? Wybierz, wpisuj¹c cyfrê z zakresu 1-11 \n";    //Zapytanie o ³¹czn¹ iloœæ porcji
            cin >> orderSize;

            if (orderSize < 1 || orderSize > 11)
            {
                do
                {
                    cout << "\n\n Maksymalna ilosc pozycji w naszym menu wynosi 11! Wybierz cyfrê z zakresu 1-11!\n";
                    cin >> orderSize;
                } while (orderSize < 1 || orderSize>11);
            }

            cout << "\n\nWybierz zatem interesuj¹ce Ciebie pozycje \n";
            int j = 1;
            int result = 0;

            for (i = 0; i < orderSize; i++)
            {
                cout << "Podaj numer swojej " << j << " pozycji dania z menu (1 - 11), 0 - zacznij od nowa, 12 - wyjdŸ z aplikacji \n";        //wprowadzanie konkretnych pozycji z menuu do tablicy
                cin >> dinnerNum;

                j += 1;

                if (dinnerNum < 0 || dinnerNum > 12)
                {
                    do
                    {
                        cout << "\nNiepoprawna pozycja! WprowadŸ numer pozycji ponownie! (1 - 11), 0 - zacznij od nowa, 12 - wyjdŸ z aplikacji\n";
                        cin >> dinnerNum;
                    } while (dinnerNum < 0 || dinnerNum > 12);
                }

                if (dinnerNum == 0 || dinnerNum == 12)
                {
                    if (dinnerNum == 12)
                        ExitProgram = true;

                    result = 1;
                    break;
                }

                cout << "\nPodaj iloœæ porcji z aktualnie wybranej pozycji. Maksymalnie mo¿esz zamówiæ 5 porcji z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
                cin >> dinnerAmount;
                cout << " \n\n";

                if (dinnerAmount < 1 || dinnerAmount > 5)
                {
                    cout << "Niepoprawna iloœæ porcji! Wybierz iloœæ porcji ponownie! \n";
                    do
                    {
                        cout << "Podaj iloœæ porcji z aktualnie wybranej pozycji. Maksymalnie mo¿esz zamówiæ 5 porcji z danej pozycji (aktualnie wybrana pozycja: " << dinnerNum << ") \n";
                        cin >> dinnerAmount;
                    } while (dinnerAmount < 1 || dinnerAmount > 5);
                }
                SummaryDinnerTab[dinnerNum - 1] = dinnerAmount;

                if (dinnerNum == 11)
                {
                    for (int i = 0; i < dinnerAmount; i++)
                    {
                        result = UserDish(i);

                        if (result == 1)
                            break;
                    }

                    if (result == 1)
                        break;
                }
            }

            if (result == 1)
                continue;

            //Podsumowanie

            if (SummaryDinnerNameShow() == 1)
                continue;

            cout << "Twoje finalne zamówienie, to: \n\n";
            FinalOrderShow();
            cout << endl;
            cout << "Czy chcesz wyœwietliæ pe³n¹ wersjê wybranych pozycji? 0 - zacznij od nowa, 1 - tak, 2 - nie, 3 - wyjdŸ z aplikacji\n";
            cin >> fullVersionMenu;

            if (fullVersionMenu == 1)
            {
                ShowFullVersionMenu();
            }
            else if (fullVersionMenu == 0)
            {
                continue;
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
        {
            system("cls");
            cout << "Podaj inn¹ liczbê!" << endl;;
            continue;
        }
    }

    return 0;
}