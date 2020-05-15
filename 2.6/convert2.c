#include <stdio.h>
#include <stdlib.h>

/* si al programa se le elimina la condicional
este va a querer aceder a elementos de la matriz que no existen y se le llama fallo de segmentacion

*/

void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}


int main(int argc, char *argv[]){
    int i, count;



   if(argc < 3)                            //si se usan menos de tres argumentos
    usage(argv[0]);                     //muestra el mensage de informacion de uso y sal
    count = atoi(argv[2]);                    //convierte el 2 argumento en un entero
    printf("repeating %d times..\n", count);

    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]);   //muestra el 1 argumento

}
