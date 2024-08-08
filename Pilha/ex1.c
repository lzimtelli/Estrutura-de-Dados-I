#include <stdio.h>
#define TAMMAX 100

typedef struct sPilha{
    int itens[TAMMAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *s){
    s->topo = -1;
}

int verificarVazia(Pilha *s){
    if(s->topo == -1){
        return 1;
    }
    return 0;
}

int verificarCheia(Pilha *s){ //sem ponteiro se nao for manuipular o codigo
    if(s->topo == TAMMAX - 1){
        return 1;
    }
    return 0;
}

void empilhar(Pilha *s, int val){
    if(verificarCheia(s)){//overflow
        printf("Erro: Pilha cheia");
        return;
    } else {
        ++s->topo;
        s->itens[s->topo] = val;
    }
}

void desempilhar(Pilha *s){
    char aux;
    if(verificarVazia(s)){ //underflow
        printf("Erro: Pilha Vazia");
        return -1;
    } else {
        aux = s->itens[s->topo];
        s->topo--;
        return aux;
    }
}

int main(){
    Pilha s;
    int val;

    inicializarPilha(&s);
    verificarCheia(&s);
    verificarVazia(&s);
    empilhar(&s, val);
}