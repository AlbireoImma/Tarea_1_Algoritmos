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

}

char* secreto::calcular(int k){
    char* des = new char[cant_letras];
    for(int i = 0; i < cant_letras; i++){
        des[i]=(char)"";
    }
    int* niveles = new int[cant_letras-1];
    
    return des;
}
