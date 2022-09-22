#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int main(){
    float *x1, *x2;
    int n;
    clock_t t;

    printf("Quantos numeros serao inseridos?\n");
    scanf("%d", &n);
    
    x1 = malloc(n * sizeof(float));
    x2 = malloc(n * sizeof(float));

    for(int i = 0; i < n; i++){
        float num;
        printf("Numero %d:", i+1);
        scanf("%f", &num);
        x1[i] = num;
        x2[i] = num;
    }

    
    t = clock();
    hSort(x1, n, comparador);
    t = clock() - t;
    
    printf("\nTempo do hSort: %1f", ((double)t)/(CLOCKS_PER_SEC/1000));

    printf("\nOrdem crescente:");
    for(int i = 0; i < n; i++){
        printf(" %.1f", x1[i]);
    }

    t = clock();
    qsort(x2, n, sizeof(float), comparador);
    t = clock() - t;

    printf("\n\nTempo do qsort: %1f", ((double)t)/(CLOCKS_PER_SEC/1000));

    printf("\nOrdem crescente:");
    for(int i = 0; i < n; i++){
        printf(" %.1f", x2[i]);
    }
}