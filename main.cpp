#include <iostream>
#include <stdlib.h> // system pause, cls etc
#include <cstdio>
#include "Menus.h"

using namespace std;

int main()
{
    int opcion;

    while (true)
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            seleccionIndividual(opcion);
            break;
        case 2:
            seleccionIndividual(opcion);
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}
