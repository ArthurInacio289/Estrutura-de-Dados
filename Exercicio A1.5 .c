#include <stdio.h>

// Faça um programa que leia os valores de uma matriz A de 5 linhas e 3
// colunas. Construir uma matriz B de mesmo tamanho, que será formada
// pelo fatorial dos elementos da matriz A.
// Função para calculo de fatorial - Check
// preencher elementos matriz A, Acessar cada elemento da matriz A, Salvar em B os valores fatoriais de cada elemento.

int Fatorial(int v)
{
    int R = 1;
    for (int i = v; i != 0 || i < 0; i--)
    {
        R = R * i;
    }
    return R;
}

int main(int argc, char const *argv[])
{
    int matrizA[5][3];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Defina o numero referente a linha %d e a coluna %d :", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    int matrizB[5][3];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrizB[i][j] = Fatorial(matrizA[i][j]);
            printf("%d ", matrizB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
