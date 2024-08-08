#include <stdio.h>
#define TAMMAX 4

typedef struct sFila{
    char itens[TAMMAX];
    int inicio, fim;
} FILA;

void inicializar(FILA *f){ //inicio e fim no mesmo ponto
    f->fim = TAMMAX - 1;
    f->inicio = TAMMAX - 1;
}

int fila_vazia(FILA *f){
    if(f->fim == f->inicio)
        return 1;
    return 0;
}

int fila_cheia(FILA *f){
    if(f->inicio == f->fim)
        return 1;
    return 0;
}    

void enfileirar(FILA *f, int x){
    if(f->fim == (TAMMAX - 1)){ //verifica se o fim é o "comeco da fila"
        f->fim = 0; //se estiver, aloca ela como 0
    } else {
        (f->fim)++; //caso o contrario, aumenta o fim
    }
    if(fila_cheia(f)){ //(f->fim == f->inicio)
        printf("Erro: fila cheia\n");
        (f->fim)--; //se a fila estiver cheiam diminui o fim
        if(f->fim == -1) // se a fila for -1, realoca o tamanho 
            f->fim == TAMMAX - 1;
        return;
    }
    f->itens[f->fim] = x; //caso tudo ao contrario, aloca o valor no fim da fila
}

int desenfileirar(FILA *f){
    int aux = 0;

    if(!fila_vazia(f)){ //verifica se a fila nao está vazia
        if(f->inicio == TAMMAX - 1){ //se o tamanho for o do inicio
            f->inicio = 0; //aloca pra zero
        } else {
            f->inicio++; //caso o contraio, ele aumenta o inicio
        }
        aux = f->itens[f->inicio]; 
    }
    else {
        printf("Erro: Fila vazia");
    }
    return aux;
}

void imprimir_fila(FILA *f){ //esse codigo aqui nao ta funcionando
    int i = (f->inicio + 1) % TAMMAX;
    if(!fila_vazia(f)){
        printf("Fila: ");
        while (i != ((f->fim+1) % TAMMAX)){
            printf("%c", f->itens[i]);
            i = (i + 1) % TAMMAX;
        }
    } else
        printf("Fila vazia");
}

int main(){
    FILA fila;
    inicializar(&fila);
    char aux;
    
    enfileirar(&fila, 'a');
    enfileirar(&fila, 'b');
    enfileirar(&fila, 'c');
    enfileirar(&fila, 'd');
    enfileirar(&fila, 'e');
    aux = desenfileirar(&fila);

    imprimir_fila(&fila);
    printf("\n\n%c", aux);
}