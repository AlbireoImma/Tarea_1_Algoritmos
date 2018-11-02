#include <stdio.h>
#include <iostream>

using namespace std;

class Rango{
    private:
    long unsigned int inicio;
    long unsigned int largo;
    public:
    Rango();
    Rango(long unsigned int i, long unsigned int l);
    ~Rango();
    long unsigned int getInicio();
    long unsigned int getLargo();
    void setInicio(long unsigned int i);
    void setLargo(long unsigned int l);
    void print();
    int newRango(int nivel, int num);
};
Rango::Rango(){
    inicio = 0;
    largo = 0;
}
Rango::Rango(long unsigned int i, long unsigned int l){
    inicio = i;
    largo = l;
}
Rango::~Rango(){

}
long unsigned int Rango::getInicio(){
    return inicio;
}
long unsigned int Rango::getLargo(){
    return largo;
}
void Rango::setInicio(long unsigned int i){
    inicio = i;
}
void Rango::setLargo(long unsigned int l){
    largo = l;
}
void Rango::print(){
    cout << "Inicio: " << inicio << " ,Largo: " << largo << endl;
}

int Rango::newRango(int nivel, int numero){
    int segmento;
    int multiplo;
    segmento = largo/nivel;
    largo = segmento;



    
    
    int n;
    n = 0;
    

    while (true){
        if (numero <= inicio + segmento -1){
            break;
        }
        else {
            n++;
            inicio = inicio + segmento;
            //cout << inicio << endl;
            break;
        }
    }
    
    return n;

}


// int main(int argc, char const *argv[])
// {
//     Rango prueba;
//     prueba = Rango(1, factorial(26));
//     long unsigned int guardar;
    
//     for(int i = 1; i < 27; i++)
//     {
//         cout << i << endl;
//         guardar = prueba.newRango(i, 165432);
//         printf("posicion %lu\n", guardar);
//         prueba.print();
//     }
    
//     prueba.print();
//     return 0;
// }
