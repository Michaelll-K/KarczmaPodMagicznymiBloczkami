#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <locale.h>
#include "MenuManager.h"

using namespace std;

bool ExitProgram;
//Globalna zmienna uzupe�niana przez funkcj� GetMenu()
extern string Menu[11][5];

int main()
{
    setlocale(LC_ALL, "polish");
    ExitProgram = false;
    
    return 0;
}