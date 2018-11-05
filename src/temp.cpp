#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

unsigned long long int factorial_parte(unsigned long long int x, int t){
    unsigned long long int total = x;
    
    if(x - t != 0){
        for(int i = 1; i < t; i++){
            if (x-i != 0 && (ULLONG_MAX / x-i) < total) {
                    return 0;
            }
            cout << "multiplico por: " << x - i << endl; 
            total = total * (x-i);
        }
        return total;
    }
    return 0;
}


int main(int argc, char const *argv[]){
    unsigned long long int t;
    for (int i = 0; i <= 10; i++){
        t = factorial_parte(10, i+1);
        cout << "nivel; " << i +1 << (i < 9? "; ": ";") << " numero: " << t << endl; 
        
    }
    return 0;
}
