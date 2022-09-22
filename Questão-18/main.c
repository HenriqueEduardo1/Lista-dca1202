#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void soma_vetor(int *va, int *vb, int *vr, int n){
    for(int i = 0; i < n; i++){
        vr[i] = va[i] + vb[i];
    }
}

int main(){
    int n;
    int *va, *vb, *vc;

    printf("Qual o tamanho dos vetores?\n");
    scanf("%d", &n);

    va = malloc(n * sizeof(int));
    vb = malloc(n * sizeof(int));
    vc = malloc(n * sizeof(int));

    printf("\npreencha o primeiro vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d valor: ",(i+1));
        scanf("%d",&va[i]);
    }

    printf("\npreencha o segundo vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d valor: ",(i+1));
        scanf("%d",&vb[i]);
    }

    soma_vetor(va,vb,vc,n);

    printf("\nSoma dos vetores\n");
    for(int i = 0; i < n; i++){
        printf(" %d", vc[i]);
    }

    free(va);
    free(vb);
    free(vc);
}