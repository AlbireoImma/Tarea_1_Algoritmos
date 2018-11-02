#include <iostream>
#include <stdio.h>
#include <string.h>
#include "test.h"

using namespace std;

string backtracking(string palabra, string nuevo, Rango rango, long int posicion, long int nivel){
    if(nivel > palabra.size()){
        return nuevo;
    }
    else{
        nuevo.insert(rango.newRango(nivel, posicion), 1, palabra.at(nivel-1));
        backtracking(palabra, nuevo, rango, posicion, nivel + 1);
    }
}

string previo(string palabra, long int numero){
    Rango inicial = Rango(1, factorial(palabra.size()));
    string combinado;
    return backtracking(palabra, combinado, inicial, numero, 1);
}
