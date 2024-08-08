#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    int info;
    struct sNo *esq;
    struct sNo *dir;
} NO;

void init(NO **raiz) {
    *raiz = NULL;
}

NO *getnode() {
    return (NO *) malloc(sizeof(NO));
}

int empty(NO *raiz) {
    if(raiz == NULL)
        return 1;
    return 0;
}

void inserirNo(NO **raiz, int x) {
    if (empty(*raiz)) {
        *raiz = getnode();
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->info = x;
    } else {
        if (x < (*raiz)->info) {
            inserirNo(&((*raiz)->esq), x);
        } else {
            inserirNo(&((*raiz)->dir), x);
        }
    }
}

void exibirPreOrdem(NO *raiz) {
    if (!empty(raiz)) {
        printf("%d\t", raiz->info);
        exibirPreOrdem(raiz->esq);
        exibirPreOrdem(raiz->dir);
    }
}

void exibirEmOrdem(NO *raiz) {
    if (!empty(raiz)) {
        exibirEmOrdem(raiz->esq);
        printf("%d\t", raiz->info);
        exibirEmOrdem(raiz->dir);
    }
}

void exibirPosOrdem(NO *raiz) {
    if (!empty(raiz)) {
        exibirPosOrdem(raiz->esq);
        exibirPosOrdem(raiz->dir);
        printf("%d\t", raiz->info);
    }
}

int soma(int x){
    return x < 10 ? x : soma(x / 10) + x % 10;
}

int main(){
    NO *raiz;
    init(&raiz);

    inserirNo(&raiz, 11);
    inserirNo(&raiz, 9);
    inserirNo(&raiz, 12);

    exibirPreOrdem(raiz);
    printf("\n");
    exibirEmOrdem(raiz);
    printf("\n");
    exibirPosOrdem(raiz);
    printf("\n");

    printf("%d", soma(123));
}