#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    struct cell *next;
    int info;
} CELULA;

typedef struct sFila{
    CELULA *inicio;
    CELULA *fim;
} FILA;

void init(FILA **fila){
    *fila = (FILA *)malloc(sizeof(FILA));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}

CELULA *getNode(){
    return (CELULA *)malloc(sizeof(CELULA));
}

void freeNode(FILA *q){
    free(q);
}

int empty(FILA *fila){
    if(fila->inicio == NULL)
        return 1;
    return 0;
}

void enfileirar(FILA **fila, int x){
    CELULA *aux = getNode();
    if(aux != NULL){
        aux->info = x;
        aux->next = NULL;
        if(empty(*fila)){
            (*fila)->inicio = aux;
            (*fila)->fim = aux;
        } else {
            (*fila)->fim->next = aux;
            (*fila)->fim = aux;
        }
    } else {
        printf("\nError");
    }
}

int desenfileirar(FILA **fila){
    CELULA *aux;
    int x;

    if(!empty(*fila)){
        aux = (*fila)->inicio;
        (*fila)->inicio = (*fila)->inicio->next;
        if((*fila)->inicio == NULL)
            (*fila)->fim = NULL;
    }
}

void apresentarFila(FILA *fila) {
    CELULA *atual = fila->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->next;
    }
    printf("\n");
}



int main (){
    FILA *fila;
    init(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);

    apresentarFila(fila);
}