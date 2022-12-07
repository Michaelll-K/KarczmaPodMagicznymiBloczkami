#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

string Menu[11][5];
string Products[6][3];
int SummaryDinnerTab[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
//tablica zbieraj¹ca iloœæ zamówionych rzeczy po indeksach
int confirm;

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
    GetMenu("TestMenu.txt");
    cout << "Nasze aktualne menu: \n" << endl;
    for (int i = 0; i < 11; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cout << Menu[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}


void ShowDinnerAmountSummary()
{
    cout << "Tablica zamówionych rzeczy: ";
    for (int k = 0; k < 11; k++) 
    {
        cout << SummaryDinnerTab[k];

    }
    cout << endl;
    cout << "\n" << endl;
}
//tablica do diagnozowania zamówienia pozycji na poszczególnych indeksach

void DinnerSummaryEdit()
{
    int dinnerIndex;
    int dinnerPortionIndex;
    cout << "\n\nKtóre danie chcesz edytowaæ? Podaj numer pozycji \n";
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
    cout << "Dobry wybór! \n";
}


void SummaryDinnerNameShow()
{
    cout << "\n\n\nPodsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n\n\n";
    for (int k = 0; k < 11; k++)
    {
        if (SummaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n iloœæ porcji: " << SummaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
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

    if (confirm == 2)
    {
        DinnerSummaryEdit();
        SummaryDinnerNameShow();
    }
    else
    {
        cout << "\n\n\n\nDobry wybór! \n\n\n\n\n\n\n";
    }
}


void ShowFullVersionMenu() {
    cout << "Podsumowanie \n\n";
    cout << "Twoje wybory, to: \n\n";
    for (int k = 0; k < 11; k++)
    {
        for (int l = 0; l < 5; l++)
        {
            if (SummaryDinnerTab[k] != 0)
            {
                cout << " " << Menu[k][l] << " ";
            }
        }
        cout << endl;
    }
}


void FinalOrderShow() {
    for (int k = 0; k < 11; k++)
    {
        if (SummaryDinnerTab[k] != 0)
        {
            cout << Menu[k][1] << "\n iloœæ porcji: " << SummaryDinnerTab[k] << "\n Pozycja w menu: " << Menu[k][0];
            cout << endl;
            cout << "\n" << endl;
        }
    }
}
