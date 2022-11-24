#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

string Menu[11][5];

/// <summary>
/// Funkcja wype�nia tablic� dwuwymiarow� Menu[][] z ca�ym menu
/// �eby skorzysta� z funcji trzeba j� wywo�a� przed zacz�ciem pracy z tablic�
/// </summary>
/// <param name="path">�cierzka do pliku (testowo wpisywa� "TestMenu.txt")</param>
/// <returns>Wype�nia 11 elementow� tablic� dwuwymiarow� z tablicami 5 elementowymi o nazwie Menu</returns>
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