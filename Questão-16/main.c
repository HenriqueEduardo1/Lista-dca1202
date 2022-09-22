#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparador(const void *a, const void *b){
   return (*(float*)a - *(float*)b); 
}

void hSort(float *v, int n, int (*comp)(const void*,const void*)){
    float aux;
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > i; j--){
            if(comp(v+j-1, v+j) > 0){
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux; 
            }
        }
    }
}

int main(void){
    float *x;
    int n;

    printf("Quantos numeros serao inseridos?\n");
    scanf("%d", &n);

    x = malloc(n * sizeof(float));
 
    for(int i = 1; i <= n; i++){
        printf("\nNumero %d:", i);
        scanf("%f", &x[i-1]);
    }
    
    hSort(x, n, comparador);

    printf("Ordem crescente: \n");
    for(int i = 0; i < n; i++){
        printf("\n%.1f", x[i]);
    }
 
    free(x);
}