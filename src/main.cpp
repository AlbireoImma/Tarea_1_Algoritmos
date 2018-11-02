#include <stdio.h>
#include <iostream>
#include <string>



using namespace std;

// contador global para las combinaciones
int act; 
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
