#include <stdio.h>
#define TAMVETOR 12

int menu()
{
    int resposta;
    printf("\n1. Ler vetor");
    printf("\n2. Ler Posicoes");
    printf("\n3. Realizar Soma");
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

int getX(int vetor[])
{
    int posicao = -1, valor;
    printf("\nDigite a posicao X a ser selecionada: ");
    scanf("%d", &posicao);

    valor = vetor[posicao];

    return valor;
}

int getY(int vetor[])
{
    int posicao = -1, valor;
    printf("\nDigite a posicao Y a ser selecionada: ");
    scanf("%d", &posicao);

    valor = vetor[posicao];

    return valor;
}

int somar(int x, int y){
    int soma;

    soma = x + y;

    return soma;
}

void apresentarSoma(int soma){
    printf("\nResultado da soma dos valores da posicao X e Y: %d\n", soma);
}

int main()
{
    int escolha, i = 0, posX, posY, saida = 0, resultado;
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

        case 2: // selecionar x e y
            posX = getX(vetor);
            posY = getY(vetor);
            break;

        case 3: //somar
            resultado = somar(posX, posY);
            apresentarSoma(resultado);
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