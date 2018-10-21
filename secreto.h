#include <iostream>
#include <new>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <math.h>
using namespace std;

class secreto
{
private:
    char* palabra;
    int cant_letras;
public:
    secreto(char* string);
    ~secreto();
    void matriz(int k);
    char* calcular(int k);
};

secreto::secreto(char* string){
    cant_letras = strlen(string);
    palabra = new char[cant_letras];
    strcpy(palabra,string);
}

secreto::~secreto()
{
}

void secreto::matriz(int k){
    return;
}

char* secreto::calcular(int k){
    char *des = new char[cant_letras];
    memset(des,' ',sizeof(des));
    int* niveles = new int[cant_letras-1];
    int* posiciones = new int[cant_letras-1];
    int aux;
    for(int i = 0; i < cant_letras-1; i++)
    {
        if (i == 0) {
            aux=ceil((k*1.0)/(cant_letras));
            niveles[i]=k;
        } else {
            niveles[i]=aux;
            aux = ceil(aux/(cant_letras-i));
        }
    }
    for(int i = 0; i < cant_letras-1; i++)
    {
        aux = niveles[i]%(cant_letras-i);
        if (aux == 0) {
            posiciones[i] = cant_letras;
        } else {
            posiciones[i] = aux;
        }
    }
    for(int i = 0; i < cant_letras-1; i++)
    {
        cout << "nivel: " << cant_letras-1-i << " letra: " << palabra[cant_letras-i-1];
        cout << " posicion: " << posiciones[i] << " con auxiliar: "<< niveles[i] <<"\n";
        des[posiciones[i]-1]=palabra[cant_letras-i-1];
    }
    for(int i = 0; i < cant_letras-1; i++)
    {
        if (des[i] == ' ') {
            des[i]=palabra[0];
        }
    }
    cout << "Solicitado: (" << palabra << "," << k << ") Obtenido: " << des << "\n";
    return des;
}
