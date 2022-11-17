#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

//Deklarowanie struktury (tak jest naj�atwiej zwr�ci� tablic� dwudymiarow�)
struct Menu
{
	string values[11][5];
};

/// <summary>
/// Funkcja do zwracania tablicy z ca�ym menu przez tablic� dwuwymiarow�
/// �eby skorzysta� z funcji trzeba stworzy� instancj� struktury Menu i przypisa� do niego warto�� zwrotn� z metody
/// Aby skorzysta� z wynuku nale�y odnie�� si� do elementu struktury poprzez .values
/// </summary>
/// <param name="path">�cierzka do pliku (testowo wpisywa� "TestMenu.txt")</param>
/// <returns>Zwraca strukture z 11 elementow� tablic� dwuwymiarow� z tablicami 5 elementowymi</returns>
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