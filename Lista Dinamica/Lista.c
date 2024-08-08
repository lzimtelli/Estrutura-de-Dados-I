#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    struct cell *next;
    int info;
} CELULA;

CELULA *getNode(){
    return (CELULA *)malloc(sizeof(CELULA));
}

void freeNode(CELULA *q){
    free(q);
}

void init(CELULA **lista){
    (*lista) = NULL;
}

int empty(CELULA *lista){
    if(lista == NULL)
        return 1;
    return 0;
}

void inserirInicio(CELULA **lista, int x) {
    CELULA *aux = getNode(); //cria para inserir e seta o nó
    if(aux != NULL) {
        aux->info = x; //recebe oq vai adicionar
        aux->next = *lista; //define pro primeiro lugar da lista
        *lista = aux; //recebe as informacoes
    } else {
        printf("\nErro!");
        return;
    }
}

void inserirFim(CELULA **lista, int x){
    CELULA *insert = getNode();
    CELULA *temp;
    if(insert != NULL){
        insert->info = x;
        insert->next = NULL;
        if(empty(*lista)){
            (*lista) = insert;
        } else {
            temp = *lista;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = insert;
        }
    }
}

void removerInicio(CELULA **lista){
    CELULA *aux = (*lista);

    if(!empty(*lista)){
        (*lista) = aux->next;
        freeNode(aux);
    } else {
        printf("\nErro, lista vazia");
        return;
    }
}

void removerFim(CELULA **lista){
    CELULA *aux = (*lista);
    CELULA *temp;

    if(!empty(*lista)){
        while(aux->next != NULL){
            temp = aux;
            aux = aux->next;
        }
        temp->next = NULL;
        freeNode(aux);
    } else {
        printf("\nErro, lista vazia");
        return;
    }
}

void apresentar(CELULA *lista){
    while(!empty(lista)){
        printf("%d\t ", lista->info);
        lista = lista->next;
    }
    printf("\n");
}

int main(){
    CELULA *lista;
    init(&lista);

    inserirInicio(&lista, 10);
    printf("Inserir inicio: ");
    apresentar(lista);

    inserirInicio(&lista, 20);
    printf("Inserir inicio: ");
    apresentar(lista);

    inserirFim(&lista, 30);
    printf("Inserir fim: ");
    apresentar(lista);

    removerInicio(&lista);
    printf("Remover inicio: ");
    apresentar(lista);

    removerFim(&lista);
    printf("Remover Fim: ");
    apresentar(lista);
}