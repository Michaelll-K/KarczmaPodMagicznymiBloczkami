#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "UserManager.h"

using namespace std;

string Menu[11][5];
string Products[29][3];
//tablica zbieraj¹ca iloœæ zamówionych rzeczy po indeksach
int SummaryDinnerTab[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int confirm;

extern string UserDishesDetails[5][2];
extern bool ExitProgram;

/// <summary>
/// Funkcja wype³nia tablicê dwuwymiarow¹ Menu[][] z ca³ym menu 
/// ¯eby skorzystaæ z funcji trzeba j¹ wywo³aæ przed zaczêciem pracy z tablic¹
/// </summary>
/// <param name="path">Œcierzka do pliku (testowo wpisywaæ "TestMenu.txt") </param>
/// <returns>Wype³nia 11 elementow¹ tablicê dwuwymiarow¹ z tablicami 5 elementowymi o nazwie Menu</returns>
void GetMenu(string path)
{
	int lineIterator = 0;
	int cellIterator = 0;

	string cell = "";

	ifstream file(path);
	string line;

	while (getline(file, line)) 
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ';')
				cell = cell + line[i];
			else
			{
				Menu[lineIterator][cellIterator++] = cell;
				cell = "";
			}
		}
		lineIterator++;
		cellIterator = 0;
	}

	file.close();
}

/// <summary>
/// Funkcja wype³nia tablicê dwuwymiarow¹ Products[][] ze wszystkimi produktami 
/// ¯eby skorzystaæ z funcji trzeba j¹ wywo³aæ przed zaczêciem pracy z tablic¹
/// </summary>
/// <param name="path">Œcierzka do pliku (testowo wpisywaæ "TestProducts.txt") </param>
/// <returns>Wype³nia 11 elementow¹ tablicê dwuwymiarow¹ z tablicami 5 elementowymi o nazwie Products</returns>
void GetMenuOfProducts(string path)
{
	int lineIterator = 0;
	int cellIterator = 0;

	string cell = "";

	ifstream file(path);
	string line;

	while (getline(file, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ';')
				cell = cell + line[i];
			else
			{
				Products[lineIterator][cellIterator++] = cell;
				cell = "";
			}
		}
		lineIterator++;
		cellIterator = 0;
	}

	file.close();
}


void ShowMenu()
{
    GetMenu("Menu.txt");
    cout << "Nasze aktualne menu: \n" << endl;
    cout << endl;
    for (int i = 0; i < 11; i++) 
    {
        cout << Menu[i][0] << ". " << Menu[i][1] << " (" << Menu[i][3] << ")" << endl;
        cout << "cena: " << Menu[i][2] << ", ostroœæ: " << Menu[i][4] << endl;
        cout << endl;
    }
    cout << "\n" << endl;
}

void DinnerSummaryEditShow()
{
    cout << endl;
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        if (SummaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n Iloœæ porcji: " << SummaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0] << endl;
            cout << endl;
        }
    }
    do 
    {
        cout << "Czy potwierdzasz swoje zamówienie? \n";
        cout << "0 - rozpocznij jeszcze raz \n";
        cout << "1 - tak \n";
        cout << "2 - nie \n";
        cout << "3 - zakoñcz program \n";
        cin >> confirm;
    } while (confirm != 1 && confirm != 2 && confirm != 0 && confirm != 3);

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


        cout << "Podaj now¹ iloœæ porcji, wpisz 0 je¿eli chcesz usun¹æ pozycjê \n";
        cin >> dinnerPortionIndex;

        if (dinnerPortionIndex < 0 || dinnerPortionIndex > 5)
        {
            do
            {
                cout << "Niepoprawna iloœæ porcji! WprowadŸ numer porcji ponownie (1 - 5), lub wpisz 0, ¿eby zrezygnowaæ z tej pozycji! \n";
                cin >> dinnerPortionIndex;
            } while (dinnerPortionIndex < 0 || dinnerPortionIndex>5);
        }


        SummaryDinnerTab[dinnerIndex - 1] = dinnerPortionIndex;
        cout << "Twoje zamówienie teraz to: \n";
        DinnerSummaryEditShow();
        if (confirm == 2)
        {
            DinnerSummaryEdit();
        }
        else
        {
            cout << "Dobry wybór! \n\n\n";
        }

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

int SummaryDinnerNameShow()
{
    DinnerSummaryEditShow();

    if (confirm == 2)
    {
        DinnerSummaryEdit();
    }
    else if (confirm == 1)
    {
        cout << "Dobry wybór! \n\n\n";
    }
    else if (confirm == 0)
    {
        return 1;
    }
    else
    {
        ExitProgram = true;
        return 1;
    }

    return 0;
}



void ShowFullVersionMenu() {
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        if (SummaryDinnerTab[k] != 0)
        {
            for (int i = 0; i < SummaryDinnerTab[k]; i++)
            {
                string ingredients = Menu[k][3];
                string spiciness = Menu[k][4];
                if (k == 10)
                {
                    ingredients = UserDishesDetails[i][0];
                    spiciness = UserDishesDetails[i][1];
                }
                cout << " " << Menu[k][0] << ". " << Menu[k][1] << "(" << ingredients << "), cena:" << Menu[k][2] << ", ostoœæ: " << spiciness << endl;
                cout << endl;
            }
        }
    }
}


void FinalOrderShow() {
    for (int k = 0; k < 11; k++)
    {
        if (SummaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n iloœæ porcji: " << SummaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0] << endl;
            cout << endl;
        }
    }
}
