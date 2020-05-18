#include <stdio.h>

void func1(){
    int i = 43;
    printf("[in func1] i @ 0x%08x = %d\n", &i, i);
}

int main(){
    int i= 42;
    printf("[in main] i @ 0x%08x = %d\n", &i, i);
    func1();
}
