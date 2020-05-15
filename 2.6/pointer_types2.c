#include <stdio.h>

int main(){
    int i;
    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5]= {1, 2, 3, 4, 5};
    char *char_pointer;
    char *int_pointer;


    char_pointer = int_array;
    int_pointer= char_array;
    /*
    hacer esta mezcla entre datos tipo int con punteros de tipo char y viceversa no genera problemas, porque se está
    hblando de espacios de memoria, un puntero tipo int guarda un byte y asimismo el char, por tanto 
    el compilador regresará un error, pero el programa se podrá ejecutar por que estamos hablando de espacia de memoria   

    eso cuando gcc -g pointer_types2.c
    (aparecerá el probable error)
    sin mebargo al ejecutar ./a.out si funciona.

    el problema es que el dato que sale no es el esperado por tanto es importante usar correctamente el tipo de dato.
    
    */
    for(i=0 ; i< 5; i++ ){
        printf("[interger pointer] points to %p, which contains the char '%c'\n",
        int_pointer, *int_pointer);
        //se suma un byte por cada vuelta en el bucle al puntero para poder cambiar 
        //el dato que señala el puntero
        int_pointer = int_pointer+1;

    }

    for(i=0 ; i< 5; i++ ){
        printf("[char pointer] points to %p, which contains the integer %d\n",
        char_pointer, *char_pointer);
        //se suma un byte por cada vuelta en el bucle al puntero para poder cambiar 
        //el dato que señala el puntero
        char_pointer = char_pointer+1;

    }
}