/*
siguiendo el commandline.c
es importante mecionar que el segudo parametro siempre se convertira en un matriz que contiene los espacios dados por 
el parametro 1, sin embargo esto puede cambiarse con una conversion de tipo estecial como atio() (de ASCII a entero), 
esta acepta como argumento un puntero a una cadena y devuelve el valor entero que representa.


otra explicación

https://riptutorial.com/es/c/topic/1285/argumentos-de-linea-de-comando

*/
#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}


int main(int argc, char *argv[]){
    /* argc es recuento de argumentos, en este caso dos (letras y el numero
    argv es una cadena qeu contiene los argumentos escritos por el usuario)
    
    */
    int i, count;

    /*
    este if asegura de que el programa se ejecute dentro de los "parametros" establecidos
    es decir, en este caso se usan 3 argumentos, el comando de ejecutable, la palabra y el entero
    por tanto si el programa no tiene esa condicional, seguirá ejecuntandose y consecuentemente
    tratando de acceder a elementos de la matriz que no existen (en este caso) o para los cuales
     no se tiene permiso, por tanto se da lo que se llama fallo se segmentación 
    */



    if(argc < 3) //si se usan menos de tres argumentos
        usage(argv[0]);   
        printf("lo que se escribe para ejecutar\n %s -- %s -- %s\n", argv[0], argv[1], argv[2]);                  //muestra el mensage de informacion de uso y sal
        count = atoi(argv[2]);                  //convierte el 2 argumento que entra en un entero
        printf("repeating %d times..\n", count);

    for(i=0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]);   //muestra el 1 argumento

}

/*
 a la hora de ejecutar se ecribe:
 -gcc convert.c
 -./a.out (frase entre comas) (numero de veces que quiero que aparezca)

*/