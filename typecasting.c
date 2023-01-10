/*
el casteo es una forma de cambiar termporalmete el tipo de dato de una variable para cierta operación
*/

#include <stdio.h>

int main(){
    int a, b;
    float c, d;
    a = 13;
    b = 5;

    c = a / b; //divide enteros
    d = (float)a / (float)b; // divide enteros cateados a floats
    printf("[intergers]\t a = %d\t b = %d\n", a, b); 

    printf("[floats]\t c = %f\t d = %f\n", c, d); 
    }