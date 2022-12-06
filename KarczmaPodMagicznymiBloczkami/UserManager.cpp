#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "UserManager.h"
#include "MenuManager.h"

using namespace std;

extern string Products[6][3];
extern bool ExitProgram;

/// <summary>
/// Funkcja do obs³ugi tworzenia dania klienta
/// </summary>
/// <returns>Zwraca stringa z wybranymi produktami oraz z ostroœci¹ dania na podstawie produktów w formacie "sk³adniki;ostroœæ"</returns>
string UserDish()
{
	cout << endl;
	cout << "Œwietnie! Wybra³eœ nasz¹ specjaln¹ pozycjê, teraz mo¿esz wybraæ sk³adniki z jakich bêdzie sk³adaæ siê Twoje danie" << endl;
	cout << endl;

	GetMenuOfProducts("TestProducts.txt");

	cout << "Oto lista naszych produktów: " << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << Products[i][0] << ". " << Products[i][1] << " ostroœæ - " << Products[i][2] << endl;
	}
	
	int choosenProduct;
	string finalProducts = "";
	int spiciness = 1;

	cout << "Wybierz z listy interesuj¹ce Ciê produkty (1 - 6), wpisz 7 aby zakoñczyæ dodawnaie: " << endl;
	cout << "Pierwszy produkt: ";
	cin >> choosenProduct;

	do
	{
		if (choosenProduct < 1 || choosenProduct > 7)
		{
			cout << "Pierwszy produkt: ";
			cin >> choosenProduct;
		}
		else
		{
			finalProducts += Products[choosenProduct - 1][1] + ", ";

			(stoi(Products[choosenProduct - 1][2]) > spiciness) ? 
				spiciness = stoi(Products[choosenProduct - 1][2]) : 
				spiciness = spiciness;

			if (choosenProduct == 0)
			{
				ExitProgram = true;
				return "";
			}

			cout << "Dodaj kolejny produkt: ";
			cin >> choosenProduct;
		}
	} while (choosenProduct != 7);

	finalProducts.pop_back();
	finalProducts.pop_back();

	cout << "Ostatecznie Twoje danie bêdzie zawiera³o: " << endl;
	cout << finalProducts << endl << endl;
	cout << "Ostroœæ Twojego dania zostanie policznona automatycznie ;)" << endl;
	

	return finalProducts + ";" + to_string(spiciness);
}