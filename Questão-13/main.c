#include <stdio.h>

/*Ponteiro para função serve para definir qual função será executada 
durante o código, dessa forma o ponteiro guarda o trecho de código.

Exemplo:
*/

void dec (int *n){
  (*n)--;
}

int main(){
    void (*fp)(int*);
 
    fp = dec;
     
    int num = 10;
    printf ("num = %d\n",num);

    dec(&num);
    printf ("num = %d\n",num);

    fp(&num) ;
    printf ("num = %d\n",num);

}
