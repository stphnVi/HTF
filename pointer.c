#include <stdio.h>
#include <string.h>

int main(){
	char str_a[20]; //una matriz de 20 caracteres
	char *pointer;  //puntero, destinado a una matriz de caracteres
	char *pointer2; // otro màs

	strcpy(str_a, "hello, world!\n");
	pointer = str_a; //situa al puntero al inicio de la matriz
	printf(pointer);

	pointer2 = pointer + 2; //pointer dos bytes màs adelante
	printf(pointer2); //lo muestra
	strcpy(pointer2, "y you guys\n"); //Lo copia en ese punto
	printf(pointer2);
}
// para ver como funcina el puntero
/*
gcc -o pointer pointer.c
./pointer
-compila-

gcc -g -o pointer pointer.c
gdb -q ./pointer
(gdb)list
(gdb) -enter-
(gdb)x/xw &pointer -direccion del puntero: direccion de lo que apunta el puntero
(gdb)print pointer -direccion de lo apuntado y lo que contiene-
(gdb)x/xw -hexadecimal/palabra
(gdb)x/s  -hexadecimal/string
*/
