#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

string Menu[11][5];

/// <summary>
/// Funkcja wype³nia tablicê dwuwymiarow¹ Menu[][] z ca³ym menu
/// ¯eby skorzystaæ z funcji trzeba j¹ wywo³aæ przed zaczêciem pracy z tablic¹
/// </summary>
/// <param name="path">Œcierzka do pliku (testowo wpisywaæ "TestMenu.txt")</param>
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