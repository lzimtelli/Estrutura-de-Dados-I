/*Marcos Paulo irritado com o controle remoto de sua televisão que só passava os canais 
em uma direção, resolveu ligar na garantia do produto solicitando um novo controle 
remoto que funcionasse corretamente (capaz de percorrer em duas direções, 
‘aumentar’ e ‘diminuir’ os canais). Utilizando como base a implementação do exercício 
6), codifique, compile e execute uma nova aplicação que seja capaz de percorrer os 
canais com o novo controle remoto. Para isso, utilize o conceito de lista linear 
duplamente encadeada circular.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sCanal{
    int num;
    char nome[50];
} CANAL;

typedef struct cell {
    CANAL cc;
    struct cell *esq, *dir;
} CELULA;

void init(CELULA **lista){
    *lista = NULL;
}

CELULA *getNode(){
    return (CELULA *)malloc(sizeof(CELULA));
}

void freeNode(CELULA *q){
    free(q);
}

int empty(CELULA *lista){
    if(lista == NULL)
        return 1;
    return 0;
}

CANAL lerCanal(){
    CANAL c;
    printf("\n\tDigite o nome do canal: ");
    fflush(stdin);
    fgets(c.nome, 50, stdin);
    if (c.nome[strlen(c.nome) - 1] == '\n')
        c.nome[strlen(c.nome) - 1] = '\0';
    printf("\n\tDigite o numero do canal: ");
    scanf("\n\t%d", &c.num);
    printf("\n\tCanal adicionado\n");
    return c;
}

void adicionar(CELULA **lista, CANAL canalInsert){
    CELULA *aux = getNode();
    if(aux != NULL){
        aux->cc = canalInsert;
        if(empty(*lista)){
            aux->dir = aux;
            aux->esq = aux;
        } else {
            aux->dir = (*lista)->dir;
            aux->esq = *lista;
            (*lista)->dir = aux;
            aux->dir->esq = aux;
        }
        *lista = aux;
    } else {
        printf("\nErro na alocacao\n");
        return;
    }
}

void aumentar(CELULA **lista){
    if(*lista != NULL)
        (*lista) = (*lista)->dir;
    else
        printf("\n\tNenhum canal disponivel\n");
}

void diminuir(CELULA **lista){
    if(*lista != NULL)
        (*lista) = (*lista)->esq;
    else
        printf("\n\tNenhum canal disponivel\n");
}

void atual(CELULA *lista){
    CELULA *aux = lista->dir;

    if(aux != NULL)
        printf("\n\tCanal %d - %s\n", aux->cc.num, aux->cc.nome);
    else
        printf("\n\tNenhum canal disponivel\n");
}

void menu(){
    printf("\n\t-----= Menu =-----");
    printf("\n\t1. Direita");
    printf("\n\t2. Esquerda");
    printf("\n\t3. Adicionar Canal");
    printf("\n\t4. Gerir Canal");
    printf("\n\t0. Sair");
    printf("\n\t:");
}

int main(){
    CELULA *lista;
    init(&lista);

    int saida = 0;
    int op;

    do{
        menu();
        scanf("\n\t%d", &op);

        switch (op){
        case 1:
            aumentar(&lista);
            atual(lista);
            break;

        case 2:
            diminuir(&lista);
            atual(lista);
            break;

        case 3: //colocar na lista
            adicionar(&lista, lerCanal());
            break;

        case 4:
            atual(lista);
            break;
        
        case 0:
            saida = 1;
            printf("\n\tVoce escolheu sair\n");
            break;

        default:
            printf("\n\tDigite uma opcao valid\n");
            break;
        }
    } while (saida != 1);
}