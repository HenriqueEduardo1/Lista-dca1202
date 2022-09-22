#include <stdio.h>
#include <stdlib.h>

void preenche_m(int **m, int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("a%d,%d: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

void imprime_m(int **m, int l, int c){
    for(int i = 0; i < l; i++){
        printf("[");
        for(int j = 0; j < c; j++){
            printf("%d ",m[i][j]);
        }printf("]\n");
    }
}

void multiplica_m(int **Ma, int **Mb, int **Mc, int lA, int cA, int cB){
    int soma = 0;

    for(int i = 0; i < lA; i++){
        for(int j = 0; j < cB; j++){
            for(int x = 0; x < cA; x++){
                soma += Ma[i][x] * Mb[x][j];
            }
            Mc[i][j] = soma;
            soma = 0;
        }
    }
}

int main(){
    int **MA, **MB, **MC;
    int lA, cA, lB, cB, lC, cC;

    printf("Quantidade de linhas da matriz A: ");
    scanf("%d",&lA);
    printf("Quantidade de colunas da matriz A: ");
    scanf("%d",&cA);

    MA = malloc(lA * sizeof(int*));
    MA[0] = malloc(lA * cA * sizeof(int));

    for(int i = 1; i < lA; i++)
        MA[i] = MA[i - 1] + cA;
    
    preenche_m(MA,lA,cA);

    printf("Quantidade de linhas da matriz B: ");
    scanf("%d",&lB);
    printf("Quantidade de colunas da matriz B: ");
    scanf("%d",&cB);

    MB = malloc(lB * sizeof(int*));
    MB[0] = malloc(lB * cB * sizeof(int));

    for(int i = 1; i < lB; i++)
        MB[i] = MB[i - 1] + cB;
    
    preenche_m(MB,lB,cB);

    lC = lA;
    cC = cB;

    MC = malloc(lC * sizeof(int*));
    MC[0] = malloc(lC * cC * sizeof(int*));

    for(int i = 1; i < lC; i++)
        MC[i] = MC[i - 1] + cC;

    multiplica_m(MA,MB,MC,lA,cA,cB);

    printf("\nMatriz A:\n");
    imprime_m(MA,lA,cA);

    printf("\nMatriz B:\n");
    imprime_m(MB,lB,cB);

    printf("\nMatriz A * B:\n");
    imprime_m(MC,lC,cC);

    free(MA[0]);
    free(MA);
    free(MB[0]);
    free(MB);
    free(MC[0]);
    free(MC);
}