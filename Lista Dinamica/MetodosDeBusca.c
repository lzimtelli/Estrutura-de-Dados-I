#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int info;
    struct cell *next;
    int acessos;
} CELULA;

CELULA *getnode(){
    return (CELULA *) malloc (sizeof(CELULA));
}

void freenode(CELULA *q){
    free(q);
}

CELULA *init(CELULA *lista){
    lista = NULL;
    return lista;
}

int empty(CELULA *lista){
    if(lista == NULL)
        return 1;
    return 0;
}

CELULA *insereInicio(CELULA *lista, int x){
    CELULA *q;

    q = getnode();
    if(q != NULL){
        q->info = x;
        q->next = lista;
        lista = q;
        return lista;
    } else {
        printf("\nErro");
        return NULL;
    }
}

CELULA *insereFim(CELULA *lista, int x){
    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q != NULL){
        q->info = x;
        q->next = NULL;

        if(empty(lista))
            lista = q;
        else {
            aux = lista;
            while(aux->next != NULL)
                aux = aux->next;

            aux->next = q;
        }
        return lista;
    } else {
        printf("\nErro");
        return NULL;
    }
}

CELULA *removeInicio(CELULA *lista){
    CELULA *q;

    q = lista;
    if(!empty(lista)){
        lista = q->next;
        freenode(q);
        return lista;
    } else {
        printf("\nErro");
        return NULL;
    }

}

CELULA *search(CELULA *lista, int x){
    CELULA *q;

    if(!empty(lista)){
        q = lista;
        while(q != NULL){
            if(q->info == x)
                return q;
            q = q->next;
        }
    }
    return NULL;
}

CELULA *removerFim(CELULA *lista){
    CELULA *remov;
    CELULA *q;

    if (!empty(lista)){
        remov = lista;
        while (remov->next != NULL)
        {
            q = remov;
            remov = remov->next;
        }
        q->next = NULL;
        freenode(remov);
        return lista;
    }else{
        printf("\nErro");
        return NULL;
    }
}

void exibirLista (CELULA *lista){
    CELULA *aux;

    aux = lista;
    while(aux != NULL){
        printf("%d\t", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

CELULA *moverPraFrente(CELULA *lista, int x) {
    printf("\nAntes de mover: ");
    exibirLista(lista);
    CELULA *anterior;
    CELULA *atual;

    anterior = NULL;
    atual = lista;

    while (atual != NULL && atual->info != x) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->next = atual->next;
            atual->next = lista;
            lista = atual;
        }
        printf("\nDepois de mover: ");
        exibirLista(lista);
    } else {
        printf("\nErro");
    }

    return lista;
}

CELULA *transposicao(CELULA *lista, int x) {
    printf("\nAntes de mover: ");
    exibirLista(lista);
    
    CELULA *predecessor;
    CELULA *atual;
    CELULA *posterior;
    int i = 1;

    if(!empty(lista)){
        if(lista->info == x){
            printf("\nErro");
            return lista;
        }

        posterior = lista->next; 
        atual = lista;
        predecessor = lista;

        while(posterior != NULL && i != 0){
            if(posterior->info == x){
                atual->next = posterior->next;
                posterior->next = atual;

                if(predecessor != atual)
                    predecessor->next = posterior;
                else
                    lista = posterior;
                i = 0;
            } else {
                predecessor = atual;
                atual = posterior;
                posterior = posterior->next;
            }
        }
        printf("\nDepois de mover: ");
        exibirLista(lista);

        if(i == 1)
            printf("\nErro");
    } else
        printf("\nLista vazia");

    return lista;
}

CELULA *contagem(CELULA *lista){
    CELULA *atual, *anterior, *proximo, *aux;

    aux = lista;
    while (aux != NULL){
        atual = lista;
        anterior = NULL;
        proximo = atual->next;

        if (atual->next == NULL)
            return lista;
        else{
            while (proximo != NULL && (atual->acessos > proximo->acessos)){
                anterior = atual;
                atual = proximo;
                proximo = atual->next;
            }
            if (anterior == NULL){
                anterior = proximo->next;
                proximo->next = atual;
                atual->next = anterior;
                lista = proximo;
            }
            else if (proximo != NULL){
                anterior->next = proximo;
                atual->next = proximo->next;
                proximo->next = atual;
            }
        }
        aux = aux->next;
    }
    return lista;
}


int main(){
    CELULA *lista;
    lista = init(lista);

    lista = insereInicio(lista, 1);
    lista = insereFim(lista, 2);
    lista = insereFim(lista, 3);
    lista = insereFim(lista, 4);

    printf("\n----------------\n");
    exibirLista(lista);

    printf("\n----------------");
    lista = moverPraFrente(lista, 3);
    printf("\n----------------");
    lista = transposicao(lista, 4);
    printf("\n----------------");
    lista = contagem(lista);

}