#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "UserManager.h"
#include "MenuManager.h"

using namespace std;

string UserDishesDetails[5][2];

extern string Products[29][3];
extern bool ExitProgram;
extern string Menu[11][5];
extern int SummaryDinnerTab[11];
extern bool OnSite;

/// <summary>
/// Funkcja do obs?ugi tworzenia dania klienta
/// </summary>
/// <returns>Zwraca stringa z wybranymi produktami oraz z ostro?ci? dania na podstawie produkt?w w formacie "sk?adniki;ostro??"</returns>
int UserDish(int iteration)
{
	if (iteration == 0)
	{
		cout << endl;
		cout << "?wietnie! Wybra?e? nasz? specjaln? pozycj?, teraz mo?esz wybra? sk?adniki z jakich b?dzie sk?ada? si? Twoje danie" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Wybierz sk?adniki do swojego kolejnego dania" << endl;
		cout << endl;
	}

	GetMenuOfProducts("Ingredients.txt");

	cout << "Oto lista naszych produkt?w: " << endl;

	for (int i = 0; i < 29; i++)
	{
		cout << Products[i][0] << ". " << Products[i][1] << " ostro??: " << Products[i][2] << endl;
	}

	int choosenProduct;
	string finalProducts = "";
	int spiciness = 1;

	cout << endl;
	cout << "Wybierz 0 aby rozpocz?? jeszcze raz, wybierz 31 aby wyj?? z aplikacji" << endl;
	cout << "Wybierz z listy interesuj?ce Ci? produkty (1 - 29), wpisz 30 aby zako?czy? dodawanie: " << endl;
	cout << "Pierwszy produkt: ";
	cin >> choosenProduct;

	do
	{
		if (choosenProduct < 0 || choosenProduct > 30)
		{
			cout << "Pierwszy produkt: ";
			cin >> choosenProduct;
		}
		else
		{
			if (choosenProduct == 0)
				return 1;

			if (choosenProduct == 31)
			{
				ExitProgram = true;
				return 1;
			}

			finalProducts += Products[choosenProduct - 1][1] + ", ";

			(stoi(Products[choosenProduct - 1][2]) > spiciness) ?
				spiciness = stoi(Products[choosenProduct - 1][2]) :
				spiciness = spiciness;

			cout << "Dodaj kolejny produkt: ";
			cin >> choosenProduct;
		}
	} while (choosenProduct != 30);

	finalProducts.pop_back();
	finalProducts.pop_back();
	
	cout << endl;
	cout << "Ostatecznie Twoje danie b?dzie zawiera?o: " << endl;
	cout << finalProducts << endl << endl;
	cout << "Ostro?? Twojego dania zostanie policznona automatycznie ;)" << endl;

	UserDishesDetails[iteration][0] = finalProducts;
	UserDishesDetails[iteration][1] = to_string(spiciness);
	return 0;
}

int DeliveryTime()
{
	int summdel = 30 + rand() % 151;

	cout << summdel << endl;

	return summdel;
}

int CalculatePrice(int dishindex)
{
	int singlePrice = stoi(Menu[dishindex][2]);
	int multipler = SummaryDinnerTab[dishindex];

	int price = singlePrice * multipler;
	return price;
}

void UserSummary(string userName, string surname, string streetName, string streetNumber, string cityName, int tableNumber)
{
	int finalPrice = 0;

	fstream bill;
	bill.open("order.txt", ios::out);
	
	cout << "Imie: " << userName << endl;
	cout << "Nazwisko: " << surname<< endl;
	cout << endl;
	bill << "Imie: " << userName << endl;
	bill << "Nazwisko: " << surname << endl;
	bill << endl;
	
	for (int i = 0; i < 11; i++) 
	{
		if (SummaryDinnerTab[i] > 0)
		{
			bill << Menu[i][1] << " x" << SummaryDinnerTab[i] << ": " << CalculatePrice(i) << " z?otych monet" << endl;
			cout << Menu[i][1] << " x" << SummaryDinnerTab[i] << ": " << CalculatePrice(i) << " z?otych monet" << endl;

			finalPrice += SummaryDinnerTab[i] * stoi(Menu[i][2]);
		}
	}

	cout << endl;
	cout << "Do zap?aty: " << finalPrice << " z?otych monet" << endl;
	bill << "Do zap?aty: " << finalPrice << " z?otych monet" << endl;
	cout << endl;

	if (OnSite)
	{
		cout << "Numer stolika: " << tableNumber << endl;
		bill << "Numer stolika: " << tableNumber << endl;
	}
	else
	{
		cout << "Planowany czas dostawy w minutach wynosi: " << endl;
		int randnum = DeliveryTime();
		bill << "Planowany czas dostawy w minutach wynosi: " << endl;
		bill << randnum << endl;
		cout << endl;
		cout << "Adres dostawy: " << streetName << " " << streetNumber << ", " << cityName << endl;
		bill << "Adres dostawy: " << streetName << " " << streetNumber << ", " << cityName << endl;
	}

	bill.close();
}