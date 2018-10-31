#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "secreto.h"

using namespace std;

class Rango{
    private:
    int inicio;
    int largo;
    public:
    Rango();
    Rango(int i, int l);
    ~Rango();
    int getInicio();
    int getLargo();
    void setInicio(int i);
    void setLargo(int l);
    void print();
    int newRango(int nivel, int num);
};
Rango::Rango(){
    inicio = 0;
    largo = 0;
}
Rango::Rango(int i, int l){
    inicio = i;
    largo = l;
}
Rango::~Rango(){

}
int Rango::getInicio(){
    return inicio;
}
int Rango::getLargo(){
    return largo;
}
void Rango::setInicio(int i){
    inicio = i;
}
void Rango::setLargo(int l){
    largo = l;
}
void Rango::print(){
    cout << "Inicio: " << inicio << " ,Largo: " << largo << endl;
}

int Rango::newRango(int nivel, int numero){
    int segmento;
    int multiplo;
    segmento = largo/nivel;
    multiplo = (numero - inicio) / segmento; //REVISAR
    
    inicio = inicio + segmento*multiplo;
    largo = segmento;
    return multiplo;
}

int main(int argc, char const *argv[])
{
    // char *palabra = new char[32];
    // int total, largo;

    // cin >> total;
    // for(int i = 0; i < total; i++)
    // {
    //     cin >> palabra;
    //     cin >> largo;
    //     secreto test = secreto(palabra);
    //     test.calcular(largo);
    // }

    Rango prueba;
    prueba = Rango(1, 24);
    int guardar;
    
    for(int i = 1; i < 5; i++)
    {
        guardar = prueba.newRango(i, 13);
        printf("posicion %d\n", guardar);
        prueba.print();
    }
    
    prueba.print();
    return 0;
}
