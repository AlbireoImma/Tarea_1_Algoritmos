#include <stdio.h>
#include <iostream>
#include <string>
#include "test.h"


using namespace std;

long long unsigned int factorial(long long unsigned int x){
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
        //cout << pos << endl;
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
int act; // contador global para las combinaciones
void permutarHelp(string palabra, string dummy, int indicador, int combinacion){
    int i, largo, lDummy;
    string helper;
    largo = palabra.size();
    lDummy = dummy.size();

    // inserto la ultima letra
    if(largo == dummy.size()) {
        act ++;
        if (act == combinacion) { // si estoy en la combinacion que quiero, termino
            cout << dummy << endl;
            return;
        }
        return;
    }
    else {
        helper = dummy;
        // if (lDummy == 0){
        //     dummy.insert(0,1,palabra.at(indicador));
        //     permutarHelp (palabra, dummy, indicador +1);

        // }
        //inserta las letras
        for(i=0; i < lDummy +1 && act != combinacion; i++){ // con la condicion de act termino todo
            dummy.insert(i,1,palabra.at(indicador));
            //llamado recursivo
            permutarHelp (palabra, dummy, indicador +1, combinacion);
            dummy = helper;
        }
    }
}

void permutar( string palabra, int combinacion){
    int i = 0;
    string dummy;
    permutarHelp(palabra,dummy,0, combinacion);
    return;
}

int main(int argc, char const *argv[]){
    char *palabra = new char[32];
    long unsigned int total, largo;

    cin >> total;
    for(long unsigned int i = 0; i < total; i++)
    {
        cin >> palabra;
        cin >> largo;
        act = 0; // contador de combinaciones
        permutar(palabra, largo);
    }
    return 0;
}
