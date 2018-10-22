#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "secreto.h"

using namespace std; 

main(int argc, char const *argv[])
{
    char *palabra = new char[32];
    int total, largo;

    cin >> total;    
    for(int i = 0; i < total; i++)
    {
        cin >> palabra;
        cin >> largo;
        secreto test = secreto(palabra);
        test.calcular(largo);
    }

    return 0;
}
