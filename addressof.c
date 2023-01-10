#include <stdio.h>

int main(){
	int int_var = 5;
	int *int_ptr;

	int_ptr = &int_var;// coloca la dirección de int_var en int_ptr

//Entonces si print int_var =5 y si print &int_var = (si dirección de memoria)
// si print int_ptr = (dirección de int_var),
//y si print &int_ptr = (dirección de memoria del puntero)
// si print *int_ptr = (printea en contenido de la direccion de memoria al cual apunta)
// es decir, en este caso 5.
}
/*
gcc -g addressof.c
gdb -q ./a.out -ya que no imprime para poder analizarlo se neesita hacer este paso-
(gdb) break 14
(gdb) run
(gdb) print int_var //lo que contiene la variable
(gdb) print &int_var


*/

