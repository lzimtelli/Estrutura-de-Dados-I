/*Desenvolva um programa em Linguagem C que dada uma lista L1 seu inverso seja 
armazenado em uma lista L2.*/

#include <stdio.h>
#define TAMMAX 4

typedef struct lista{
    char itens[TAMMAX];
    int n;
} LISTA;

void inicializar(LISTA *l){
    l->n = -1;
}

int cheia(LISTA *l){
    if(l->n + 1 == TAMMAX)
        return 1;
    else
        return 0;
}

int adicionarFim(LISTA *l, char elem){
    if(cheia(l)){
        printf("\nErro: lista cheia");
        return 1;
    }
    else {
        l->itens[l->n + 1] = elem;
        l->n = l->n + 1;
        return 0;
    }
}

int removerElemento(LISTA *l, int k){
    if(k < 0 || k > l->n){
        printf("\nErro: elemento fora dos limites");
        return 1;
    }

    char aux;

    int i;
    aux = l->itens[k];
    for(i = k; i < (l->n); i++){
        l->itens[l->n] = l->itens[l->n+1];
    }
    l->n = l->n -1;
    return aux;
}

int main(){
    LISTA L1, L2;
    char elem;
    inicializar(&L1);
    inicializar(&L2);

    adicionarFim(&L1, 'o');
    adicionarFim(&L1, 'e');
    adicionarFim(&L1, 'l');

    while (L1.n > -1){
        elem = removerElemento(&L1, L1.n);
        adicionarFim(&L2, elem);
    }

    printf("Lista L2 (inverso de L1): ");
    for (int i = 0; i <= L2.n; i++) {
        printf("%c ", L2.itens[i]);
    }
    printf("\n");
}