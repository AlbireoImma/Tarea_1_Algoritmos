#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>


using namespace std;

int main(int argc, char const *argv[]){
    unsigned long long int t = 32;
    for (int i = 0; i < 32; i++){
        cout << "nivel; " << i +1 << (i < 9? "; ": ";") << " numero: " << t + 65421<< endl; 
        t = pow(32, i+2);
    }
    return 0;
}
