#include <stdio.h>

int main(){
    int i;
    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5]= {1, 2, 3, 4, 5};

//inicializando un puntero vacio
    void *void_pointer;
    void_pointer= (void *) char_array;


    for(i=0 ; i< 5; i++ ){
        printf("[char pointer] points to %p, which contains the char '%c'\n",

        //al usar punteros vacios, su aritmetica y manipulacion tambien cambia

        void_pointer, *((char *) void_pointer));
        void_pointer = (void *) ((char *) void_pointer+1);
    }

    // cambiar la configuracion del puntero

    void_pointer= (void *) int_array;

    for(i=0 ; i< 5; i++ ){
        printf("[integer pointer] points to %p, which contains the integer %d\n",
         void_pointer, *((int *) void_pointer));
        void_pointer = (void *) ((int *) void_pointer+1);
        
    }
}