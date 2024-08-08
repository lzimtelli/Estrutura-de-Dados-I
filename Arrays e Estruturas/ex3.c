#include <stdio.h>
#define TAMVETOR 10

int menu()
{
    int resposta;
    printf("\n1. Ler vetor");
    printf("\n2. Procura vetor");
    printf("\n0. Saida");
    printf("\nDigite a opcao: ");
    scanf("%d", &resposta);

    return resposta;
}

int lerVetor(int repeticao)
{
    int leitura;
    printf("\nDigite o valor a ser alocado no vetor %d: ", repeticao);
    scanf("%d", &leitura);

    return leitura;
}

int getX(){
    int busca;
    printf("\nDigite o valor de X a ser buscado: ");
    scanf("%d", &busca);

    return busca;
}

int buscarVetor(int vetor[], int valorX){
    int retorno = -1;
    for(int i = 0; i < TAMVETOR; i++){
        if(vetor[i] == valorX){
            retorno = i;
        }
    }

    return retorno;
}

void verificaVetor(int procura){
    if(procura == -1){
        printf("\nValor nao encontrado no vetor\n");
    } else {
        printf("\nValor encontrado na posicao %d\n", procura);
    }
}

int main()
{
    int escolha, i = 0, saida = 0, posX, retornoVetor;
    int vetor[TAMVETOR];

    do
    {
        escolha = menu();

        switch (escolha)
        {
        case 1: // ler vetor
            for (i = 0; i < TAMVETOR; i++)
            {
                vetor[i] = lerVetor(i);
            }
            break;

        case 2:
            posX = getX();
            retornoVetor = buscarVetor(vetor, posX);
            verificaVetor(retornoVetor);
            break;

        case 0:
            saida = 1;
            printf("\nVoce escolher sair\n");
            break;

        default:
            printf("\nDigite uma opcao valida\n");
            break;
        }
    } while (saida != 1);
}