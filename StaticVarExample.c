#include <stdio.h>

/*

(REPASO )
una variable static es una variable definida en el scope de una funcion a la
cual se le puede cambiar el valor de los datos llamando a la funcion
desde otras funciones.

por eso en cada llamada la variable var en la funcion se "reinicia", sin embargo
la estatica permanece en la memoria del scope lo cual permite que cada vez que
se llame la funcion esta se actualice y permite que el valor de ella cambie lo
cual se puede ver en los prints

resultado:

[int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 5
         [int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 6
         [int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 7
         [int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 8
         [int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 9
         [int main] static_var = 1337
         [int function] var = 5
         [int function] static_var = 10
*/
void function(){
    int var = 5;
    static int static_var = 5;
    printf("\t [int function] var = %d\n", var);
    printf("\t [int function] static_var = %d\n", static_var);
    var++;
    static_var++;

}
int main(){
    int i;
    static int static_var = 1337;
    for(i=0; i<=5; i++){
        printf("\t [int main] static_var = %d\n", static_var);
        function();
    }


}