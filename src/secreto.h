#include <iostream>
#include <stdio.h>
#include <string.h>
#include "test.cpp"

using namespace std;

string backtracking(string palabra, string nuevo, Rango rango, long intposicion, long intnivel){
    if(nivel > palabra.size()){
        return nuevo;
    }
    else{
        nuevo.insert(rango.newRango(nivel, posicion), 1, palabra.at(nivel-1));
        backtracking(palabra, nuevo, rango, posicion, nivel + 1);
    }
}

string previo(string palabra, long intnumero){
    Rango inicial = Rango(1, palabra.size());
    string combinado;
    return backtracking(palabra, combinado, inicial, numero, 1);
}