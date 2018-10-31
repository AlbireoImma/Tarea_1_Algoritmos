#include <stdio.h>
#include <iostream>
#include <string>
#include "test.cpp"

using namespace std;

long unsigned int factorial(long unsigned int x){
    return (x == 1 ? x : x * factorial(x - 1));
}

void backtracking(string palabra, string nuevo, Rango rango, long unsigned int posicion, long unsigned int nivel){
    if(nivel > palabra.size()){
        cout << nuevo << endl;
    }
    else{
        long unsigned int pos = rango.newRango(nivel, posicion);
        // cout << pos << endl;
        char caracter = palabra.at(nivel - 1);
        // cout << caracter << endl;
        cout << pos << endl;
        nuevo.insert(pos, 1, caracter);
        // cout << nuevo << endl;
        backtracking(palabra, nuevo, rango, posicion, nivel + 1);
    }
}

void previo(string palabra, long unsigned int numero){
    Rango inicial = Rango(1, factorial(palabra.size()));
    string combinado;
    backtracking(palabra, combinado, inicial, numero, 1);
    // cout << combinado << endl;
}

int main(int argc, char const *argv[])
{
    char *palabra = new char[32];
    long unsigned int total, largo;

    cin >> total;
    for(long unsigned int i = 0; i < total; i++)
    {
        cin >> palabra;
        cin >> largo;
        previo(palabra, largo);
    }
    // cout << factorial(26) << endl;
    return 0;
}