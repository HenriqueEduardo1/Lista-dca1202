#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ordenacao_cre(float *vetor, int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
 
int main(void) {
    float *x;
    int n;

    printf("Quantos numeros serao inseridos?\n");
    scanf("%d", &n);

    x = malloc(n * sizeof(float));
 
    for(int i = 1; i <= n; i++){
        printf("\nNumero %d:", i);
        scanf("%f", &x[i-1]);
    }
    
    ordenacao_cre(x,n);

    printf("Ordem crescente: \n");
    for(int i = 0; i < n; i++){
        printf("\n%.1f", x[i]);
    }
 
    free(x);
}