#include <stdio.h>
#define TAMVETOR 10

int menu()
{
    int resposta;
    printf("\n1. Ler vetor");
    printf("\n2. Deletar valor");
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

int getX()
{
    int busca;
    printf("\nDigite o valor de X a ser buscado: ");
    scanf("%d", &busca);

    return busca;
}

void deleta(int vetor[], int x, int *tf)
{
    for (int i = 0; i < TAMVETOR; i++)
    {
        if (vetor[i] == x)
        {
            for (int aux = i; i < TAMVETOR; i++)
            {
                vetor[i] = vetor[i + 1];
            }
            (*tf)--;
            vetor[TAMVETOR - 1] = 0;
        }
    }
}

void apresentarVetor(int vetor[], int tf)
{
    for (int i = 0; i < tf; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int escolha, i = 0, saida = 0, posX;
    int vetor[TAMVETOR];
    int tf = 0;

    do
    {
        escolha = menu();

        switch (escolha)
        {
        case 1: // ler vetor
            for (i = 0; i < TAMVETOR; i++)
            {
                vetor[i] = lerVetor(i);
                tf++;
            }
            break;

        case 2:
            posX = getX();
            deleta(vetor, posX, &tf);
            apresentarVetor(vetor, tf);
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