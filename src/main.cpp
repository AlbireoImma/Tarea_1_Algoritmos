#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>


using namespace std;

// contador global para las combinaciones
unsigned long long int act; 
void permutarHelp(string palabra, string dummy, int indicador, unsigned long long int combinacion){
    int largo, lDummy;
    unsigned long long int combinaciones; // combinaciones que posiblemente salte
    string helper;
    largo = palabra.size();
    lDummy = dummy.size();
    // cout << "dummy: " << dummy << "; Nivel: " << indicador << endl;

    // Veo si es una respuesta
    if(largo == lDummy) {
        act ++;
        if (act == combinacion) { // si estoy en la combinacion que quiero, termino
            cout << dummy << endl;
            return;
        }
        return;
    }
    else {
        helper = dummy; // para volver atras
        // podar una parte:
        combinaciones = pow(largo, largo - indicador);
        if(act + combinaciones > 0 && act + combinaciones != act){
            if(act + combinaciones >= combinacion){ // si lo que busco esta en este largo de combinaciones entro
                //inserta las letras
                for(int i = 0; i < lDummy +1 && act != combinacion; i++){ // con la condicion de act termino todo
                    dummy.insert(i, 1, palabra.at(indicador)); // tomo la letra que corresponda
                    //llamado recursivo
                    // cout << "nivel:  " << indicador << endl;
                    permutarHelp (palabra, dummy, indicador + 1, combinacion);
                    // Vuelvo atras:
                    dummy = helper;
                }
            } else{
                act += combinaciones;
                return ; // vuelvo a quien me llamo y sigo buscando
            }
        }else{
            //inserta las letras
            for(int i = 0; i < lDummy +1 && act != combinacion; i++){ // con la condicion de act termino todo
                // elije
                dummy.insert(i, 1, palabra.at(indicador));
                // llamado recursivo
                // cout << "nivel:  " << largo - indicador << endl;
                permutarHelp (palabra, dummy, indicador + 1, combinacion);
                // Vuelvo atras:
                dummy = helper;
            }
        }
    }
}

void permutar(string palabra, unsigned long long int combinacion){
    permutarHelp(palabra, "", 0, combinacion);
    return;
}

int main(int argc, char const *argv[]){
    char *palabra = new char[32];
    unsigned long long int total, largo;

    cin >> total;
    for(long unsigned int i = 0; i < total; i++) {

        cin >> palabra;
        cin >> largo;
        act = 0; // contador de combinaciones
        permutar(palabra, largo);
    }
    return 0;
}
