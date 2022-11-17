#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

//Deklarowanie struktury (tak jest naj³atwiej zwróciæ tablicê dwudymiarow¹)
struct Menu
{
	string values[11][5];
};

/// <summary>
/// Funkcja do zwracania tablicy z ca³ym menu przez tablicê dwuwymiarow¹
/// ¯eby skorzystaæ z funcji trzeba stworzyæ instancjê struktury Menu i przypisaæ do niego wartoœæ zwrotn¹ z metody
/// Aby skorzystaæ z wynuku nale¿y odnieœæ siê do elementu struktury poprzez .values
/// </summary>
/// <param name="path">œcierzka do pliku (testowo wpisywaæ "TestMenu.txt")</param>
/// <returns>Zwraca strukture z 11 elementow¹ tablic¹ dwuwymiarow¹ z tablicami 5 elementowymi</returns>
Menu GetMenu(string path)
{
	Menu menu;

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
				menu.values[lineIterator][cellIterator++] = cell;
				cell = "";
			}
		}
		lineIterator++;
		cellIterator = 0;
	}

	file.close();

	return menu;
}