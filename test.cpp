#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "secreto.h"



main(int argc, char const *argv[])
{
    char string[] = "CDAB";
    secreto test = secreto(string);
    test.calcular(10);
    return 0;
}
