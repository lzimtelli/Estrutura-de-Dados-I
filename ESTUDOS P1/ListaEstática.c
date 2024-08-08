#include <stdio.h>
#define TAM 2

typedef struct lista{
    char valor[TAM];
    int n;
} LISTA;

void inicializar(LISTA *L){
    L->n = -1;
}

char acessar_elemento(LISTA *L, int n){
    if( (n < 0) || (n > (L->n)) )
        printf("Erro - elemento fora dos limites");
    else
        return (L->valor[n]);
}

int lista_buscar(LISTA *L, char val_b){
    int elem = -1; //inicializa elemento que vai ser retornado
    int i = 0;

    while(i < (L->n)){ //enquanto i < menor que tamanho da lista
        if(val_b == L->valor[i]){ //compara todos os elementos da lista com o valor desejado
            elem = i;//caso achar, atribui posicao à elemento
            break;//sai do break
        }
        i++;
    }
    return elem;//retorna posicao que o valor buscado esta, se nao achar, retorna -1
}

int lista_cheia(LISTA *L){
    if((L->n+1) == TAM)
        return 1; // lista ta cheia
    else
        return 0;//lista ainda tem espaco
}

int lista_vazia(LISTA *L){
    if(L -> n == -1)
        return 1; //lista vazia
    else //lista nao vazia
        return 0;
}

int inserir_elementofim(LISTA *L, char elem){
    if(lista_cheia(L) == 1){//verifica se a lista esta cheia
        printf("Erro, a lista esta cheia");
        return 1; //se tiver, abandona a operacao
    }
    L->valor[L->n+1] = elem; //caso o contrario, atribui elemento no valor na posicao n+1;
    L->n = L->n+1;//apos isso, aumenta o fim da fila

    return 0; //retorna 0 pra conferir, mas pode ser void
}

int inserir_posicaoK(LISTA *L, int k, char elem){//insere um elemento dentro de uma posicao K, sendo K um numero dentro da lista
    if(lista_cheia(L)){//verifica se está cheia, se tiver, para execucao
        printf("Error, lista cheia!");
        return 1;
    }
    if(k < 0 || k > L->n+1){//verifica se a posicao está dentro da lista, se nao estiver, para execucao
        printf("Erro, Elemento fora dos limites");
        return 1;
    }

    int i;//inicializa i

    for(i = (L->n+1); i > k; i--){//roda um for que recebe n+1(criar um novo espaco no fim da lista) até a posicao escolhida
        L->valor[i] = L->valor[i-1];//aloca o elemento anterior nele, para passar tudo um para frente
    }
    L->valor[k] = elem;//posicao escolhida recebe elemento novo
    L->n = L->n+1;//aumenta o tamanho da lista que ainda nao havia sido aumentado
    return 0;
}

int modificar_elemento(LISTA *L, int k, char elem){
    if(k < 0 || k > L->n){
        printf("Error: elemento fora dos limites");
        return 1;
    }

    L->valor[k] = elem;
    return 0;
}

int lista_remover(LISTA *L, int k){
    int i;
    if(k < 0 || k > L->n){
        printf("Error: elemento fora dos limites");
        return 1;
    }

    for(i = k; i < (L->n); i++){
        L->valor[i] = L->valor[i+1];
    }

    L->n = L-> n - 1;
    return 0;
}

int remover_elemento(LISTA *L, int k){
    if(k < 0 || k > L->n){//verifica se esta na lista
        printf("Erro, elemento fora dos limites");
        return 1;
    }

    int i; //inicializa auxiliar

    for(i = k; i < (L->n); i++){ //for que comeca na posicao escolhida e percore ate o final da lista
        L->valor[i] = L->valor[i+1];//a posicao vai receber seu proximo
    }

    L->n = L->n-1;//diminui o tamanho da lista
    return 0;
}

int main(){
    int suc;
    LISTA lista;
    inicializar(&lista);

    suc = inserir_elementofim(&lista, 'a');
    if(suc == 0)
        printf("Sucesso ao inserir\n");

    suc = inserir_elementofim(&lista, 'b');
    if(suc == 0)
        printf("Sucesso ao inserir\n");
    
    suc = inserir_elementofim(&lista, 'b');
    if(suc == 0)
        printf("Sucesso ao inserir\n");

    suc = inserir_elementofim(&lista, 'b');
    if(suc == 0)
        printf("Sucesso ao inserir\n");

    suc = inserir_elementofim(&lista, 'b');
    if(suc == 0)
        printf("Sucesso ao inserir\n");

    
    suc = remover_elemento(&lista, lista.n);
    if(suc == 0)
        printf("Sucesso ao remover\n");

    printf("%d", lista.n);
}