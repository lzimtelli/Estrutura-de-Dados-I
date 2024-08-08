#include <stdio.h>
#define TAMMAX 10

typedef struct deque{
    char itens[TAMMAX];
    int inicio, fim;
} DEQUE;

void inicializar(DEQUE *d){ //inicio e fim no mesmo ponto
    d->fim = TAMMAX - 1;
    d->inicio = TAMMAX - 1;
}

int verificarDeque(DEQUE *d){
    if(d->fim == d->inicio)
        return 1;
    return 0;
}  

void enfileirar(DEQUE *d, int x){
    if(d->fim == (TAMMAX - 1)){ //verifica se o fim é o "comeco do deque"
        d->fim = 0; //se estiver, aloca ela como 0
    } else {
        (d->fim)++; //caso o contrario, aumenta o fim
    }
    if(verificarDeque(d)){ //(f->fim == f->inicio)
        printf("Erro: deque cheio\n");
        (d->fim)--; //se o deque estiver cheiam diminui o fim
        if(d->fim == -1) // se o deque for -1, realoca o tamanho 
            d->fim == TAMMAX - 1;
        return;
    }
    d->itens[d->fim] = x; //caso tudo ao contrario, aloca o valor no fim do deque
}

int desenfileirar(DEQUE *d){
    int aux = 0;

    if(!verificarDeque(d)){ //verifica se o deque nao está vazio
        if(d->inicio == TAMMAX - 1){ //se o tamanho for o do inicio
            d->inicio = 0; //aloca pra zero
        } else {
            d->inicio++; //caso o contraio, ele aumenta o inicio
        }
        aux = d->itens[d->inicio]; 
    }
    else {
        printf("Erro: deque vazio");
    }
    return aux;
}

void inserirInicio(DEQUE *d, char x){
    if(d->inicio == 0){ //verifica se o inicio do deque é 0
        d->inicio = TAMMAX - 1; //caso for, aloca pro tammax - 1, fazendo ficar circular
    } else {
        (d->inicio)--; //caso contrario, diminui o inicio
    }
    if(verificarDeque(d)){ //verifica se ta cheio
        printf("\nErro: deque cheia");
        d->inicio = (d->inicio + 1) % TAMMAX; //retorna o valor, o % serve pra nao permitir que estoure o tamanho
        return; //quebra o codigo
    }
    d->itens[(d->inicio+1) % TAMMAX] = x; //aloca na posicao + 1, pq diminuiu antes de adicionar e o mesmo negocio do %
}

void removerFim(DEQUE *d){
    char aux; //char que vai receber o item que vai ser removido caso precise

    if(!verificarDeque(d)){ //verifica se nao estiva vazia
        if(d->fim == 0){ //se o fim for 0, volta pro tammax - 1, fazendo ficar circular
            d->fim = TAMMAX - 1;
        } else {
            d->fim--; //caso contrario, so diminui o fim
        }
        aux = d->itens[d->fim];
    }
    else {
        printf("\nErro: deque vazia");
    }
    return (aux); //retorna valor removido
}