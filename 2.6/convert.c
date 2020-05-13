/*
siguiendo el commandline.c
es importante mecionar que el segudo parametro siempre se convertira en un matriz que contiene los espacios dados por 
el parametro 1, sin embargo esto puede cambiarse con una conversion de tipo estecial como atio() (de ASCII a entero), 
esta acepta como argumento un puntero a una cadena y devuelve el valor entero que representa.
*/
#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}


int main(int argc, char *argv[]){
    int i, count;
    if(argc < 3) //si se usan menos de tres argumentos
        usage(argv[0]);                     //muestra el mensage de informacion de uso y sal
    count = atoi(argv[2]);                  //convierte el 2 argumento en un entero
    printf("repeating %d times..\n", count);

    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]);   //muestra el 1 argumento

}

/*
 a la hora de ejecutar se ecribe:
 -gcc convert.c
 -./a.out (frase entre comas) (numero de veces que quiero que aparezca)




*/