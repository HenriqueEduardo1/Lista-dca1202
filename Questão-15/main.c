#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparador(const void *a, const void *b){ //Função para comparar, entre dois valores, qual é o maior
   return (*(float*)a - *(float*)b); //Se o valor de a for maior do que o valor de b, então o resultado 
}                                   //será maior do que zero, indicando que a é maior que b.

int main(void) {
    float *x; //Ponteiro que apontara para onde será armazenado os valores
    int n; //Variável para armazenar a quantidade de números que serão inseridos

    printf("Quantos numeros serao inseridos?\n");
    scanf("%d", &n); //Leitura e armazenamento de um valor fornecido pelo usuário

    x = malloc(n * sizeof(float)); //Alocando o tamanho correspondente ao valor lido anteriormente
 
    for(int i = 1; i <= n; i++){ //Loop para armazenar uma quantidade n de dados
        printf("\nNumero %d:", i);
        scanf("%f", &x[i-1]); //Leitura e armazenamento de n valores fornecidos pelo usuário
    }
    
    qsort(x, n, sizeof(float), comparador); //Função que faz a ordenação em ordem crescente

    printf("Ordem crescente: \n");
    for(int i = 0; i < n; i++){ //Loop para percorrer e imprimir os valores de um vetor com tamanho n
        printf("\n%.1f", x[i]);
    }
 
    free(x); //Liberando a alocação de memória feita anteriormente
}