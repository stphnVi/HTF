/* recibir datos en forma de argumento de linea de comando, lo cual no necesita la interaccion del usuario*/

#include <stdio.h>
int main (int arg_count, char *arg_list[]){
    int i;
    printf("there were %d arguments provided:\n", arg_count);
    for(i=0; i< arg_count; i++)
        printf("argument #%d\t-\t%s\n", i, arg_list[i]);   
}

/*

para correr el programa primero se compila y se genera el ejecutable, al estar generado este y se inicia con la ejecucion
./commandline (como el ejecutable generado) entonces se escribe lo deseado, es decir;

---gcc -o sommandline commnadline.c
---./commandline (se escribe una oración)

y así a no introducir los datos con scanf(), es el usuario el que le da el valor a la variable, esto hace que el codigo 
sea más eficiente, la funcion mai tiene dos parametros: número que será el numero de argumentos y una matriz de 
cadena que contendrá cada uno de los argumentos


*/