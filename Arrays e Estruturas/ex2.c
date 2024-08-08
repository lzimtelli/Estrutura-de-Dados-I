#include <stdio.h>
#define TAMVETOR 16

int menu()
{
    int resposta;
    printf("\n1. Ler vetor");
    printf("\n2. Trocar posicao");
    printf("\n3. Apresentar vetor");
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

void substituirPosicao(int vetor[]){
    int aux;
    for(int i = 0;i < 8;i++){
        aux = vetor[i];
        vetor[i] = vetor[i+8];
        vetor[i+8] = aux;
    }
}

void apresentarVetor(int vetor[]){
    for(int i = 0; i < 16; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int escolha, i = 0, saida = 0;
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
            substituirPosicao(vetor);
            break;

        case 3:
            apresentarVetor(vetor);
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