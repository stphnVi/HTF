#include <stdio.h>

int main(){
    int i;
    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5]= {1, 2, 3, 4, 5};
    char *char_pointer;
    char *int_pointer;

    /* CON ESTOS CAMBIOS, el programa funcionará correctamente no como el pointer_types2*/

    char_pointer = (char *)int_array;
    int_pointer= (int *)char_array;
  
    for(i=0 ; i< 5; i++ ){
        printf("[interger pointer] points to %p, which contains the char '%c'\n",
        int_pointer, *int_pointer);
        //se suma un byte por cada vuelta en el bucle al puntero para poder cambiar 
        //el dato que señala el puntero

        /*CON ESTOS CAMBIOS*/
        int_pointer = (int *) ((char *)int_pointer+1);

    }

    for(i=0 ; i< 5; i++ ){
        printf("[char pointer] points to %p, which contains the integer %d\n",
        char_pointer, *char_pointer);
        //se suma un byte por cada vuelta en el bucle al puntero para poder cambiar 
        //el dato que señala el puntero

         /*CON ESTOS CAMBIOS*/
        char_pointer = (char *) ((int *)char_pointer+1);

    }
}