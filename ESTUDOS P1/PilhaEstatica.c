#include <stdio.h>
#define TAMMAX 5

typedef struct sPilha{
    char itens[TAMMAX];
    int topo;
} PILHA;

void inicializar(PILHA *p){
    p->topo = -1;
}

int pilha_empty(PILHA *p){
    if(p->topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(PILHA *p){
    if(p->topo == TAMMAX-1)
        return 1;
    return 0;
}

void push(PILHA *p, char val){
    if(pilha_cheia(p)){ //overflow
        printf("Erro: pilha cheia");
        return;
    } else {
        ++p->topo; //aumenta o topo
        p->itens[p->topo] = val; //adiciona valor no vetor itens na posicao topo
    }
}

int pop(PILHA *p){
    char aux;
    if(pilha_empty(p)){ //underflow
        printf("Erro: Pilha vazia");
        return -1;
    } else {
        aux = p->itens[p->topo];
        p->topo--;
        return aux;
    }
}

int stacktop(PILHA *p){
    if(pilha_empty(p)){ //underflow
        printf("Erro: pilha vazia");
        return -1;
    }
    return p->itens[p->topo];
}

int main(){
    char aux;
    PILHA s;
    inicializar(&s);

    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    push(&s, 'd');
    pop(&s);

    for(int i = 0;i <= s.topo; i++){
        printf("%c", s.itens[i]);
    }
    printf("%c", stacktop(&s));
}