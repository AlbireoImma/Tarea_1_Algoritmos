#include <stdio.h>
#include <iostream>
#include <gmp.h>

using namespace std;

class Rango{
    private:
    long long unsigned int inicio;
    long long unsigned int largo;
    public:
    Rango();
    Rango(long long unsigned int i, long long unsigned int l);
    ~Rango();
    long long unsigned int getInicio();
    long long unsigned int getLargo();
    void setInicio(long long unsigned int i);
    void setLargo(long long unsigned int l);
    void print();
    long long unsigned int newRango(long long unsigned int nivel, long long unsigned int num);
};
Rango::Rango(){
    inicio = 0;
    largo = 0;
}
Rango::Rango(long long unsigned int i, long long unsigned int l){
    inicio = i;
    largo = l;
}
Rango::~Rango(){

}
long long unsigned int Rango::getInicio(){
    return inicio;
}
long long unsigned int Rango::getLargo(){
    return largo;
}
void Rango::setInicio(long long unsigned int i){
    inicio = i;
}
void Rango::setLargo(long long unsigned int l){
    largo = l;
}
void Rango::print(){
    cout << "Inicio: " << inicio << " ,Largo: " << largo << endl;
}

long long unsigned int Rango::newRango(long long unsigned int nivel, long long unsigned int numero){
    long long unsigned int segmento;
    long long unsigned int multiplo;
    segmento = largo/nivel;
    multiplo = (numero - inicio) / segmento; //REVISAR

    inicio = inicio + segmento * multiplo;
    largo = segmento;
    return multiplo;
}

void factorial(long long unsigned int x, mpz_t resultado){
    mpz_set_ui(resultado, 1);
    while(x > 1){
        mpz_mul_ui(resultado, resultado, x);
        x = x - 1;
    }
}

long long unsigned int factorial(unsigned int n){
    long long unsigned int res;

    while(n > 1){
        res = res * n;
        n--;
    }

}

int main(int argc, char const *argv[]){

    mpz_t fact;
    mpz_init(fact);
    factorial(32, fact);
    mpz_out_str(stdout, 10, fact);
    mpz_clear(fact);
    unsigned int x = 32;
    cout << factorial(x) << endl;


    // Rango prueba;
    // prueba = Rango(1, factorial(26));
    // long long unsigned int guardar;

    // for(int i = 1; i < 27; i++)
    // {
    //     cout << i << endl;
    //     guardar = prueba.newRango(i, 165432);
    //     printf("posicion %lu\n", guardar);
    //     prueba.print();
    // }

    // prueba.print();
    return 0;
}
