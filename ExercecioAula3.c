#include <stdio.h>
#define TAM_A 10
#define TAM_B 7
#define TAM_C 15
#define TAM_D 9
#define T 4

void insertion(float *a)
{
    int i, j, tmp;
    for (i = 1; i < T; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && tmp < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}
void selection(float *vet, int tam)
{
    int i, j, min, x;
    for (i = 0; i <= tam - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[min])
                min = j;
        }
        x = vet[min];
        vet[min] = vet[i];
        vet[i] = x;
    }
}
void quick(float *vet, int esq, int dir)
{
    int pivo = esq, i, ch, j;
    for (i = esq + 1; i <= dir; i++)
    {
        j = i;
        if (vet[j] < vet[pivo])
        {
            ch = vet[j];
            while (j > pivo)
            {
                vet[j] = vet[j - 1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if (pivo - 1 >= esq)
    {
        quick(vet, esq, pivo - 1);
    }
    if (pivo + 1 <= dir)
    {
        quick(vet, pivo + 1, dir);
    }
}
void mergeSort(float *vetor, int posicaoInicio, int posicaoFim)
{
    int i, j, k, metadeTamanho, *vetorTemp;
    if (posicaoInicio == posicaoFim)
        return;
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *)malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));
    while (i < metadeTamanho + 1 || j < posicaoFim + 1)
    {
        if (i == metadeTamanho + 1)
        {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else
        {
            if (j == posicaoFim + 1)
            {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else
            {
                if (vetor[i] < vetor[j])
                {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else
                {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for (i = posicaoInicio; i <= posicaoFim; i++)
    {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

float soma(float V[], int size)
{
    float soma = 0;
    for (int i = 0; i < size; i++)
    {
        soma += V[i];
    }
    return soma;
}

int main(int argc, char const *argv[])
{
    float TurmaA[TAM_A], TurmaB[TAM_B], TurmaC[TAM_C], TurmaD[TAM_D];
    int i;

    for (i = 0; i < TAM_A; i++)
    {
        printf("Escreva as notas dos alunos da turma A:");
        scanf("%f", &TurmaA[i]);
    }
    for (i = 0; i < TAM_B; i++)
    {
        printf("Escreva as notas dos alunos da turma B:");
        scanf("%f", &TurmaB[i]);
    }
    for (i = 0; i < TAM_C; i++)
    {
        printf("Escreva as notas dos alunos da turma C:");
        scanf("%f", &TurmaC[i]);
    }
    for (i = 0; i < TAM_D; i++)
    {
        printf("Escreva as notas dos alunos da turma D:");
        scanf("%f", &TurmaD[i]);
    }

    float mediageral[] = {0, 0, 0, 0};

    mediageral[0] = soma(TurmaA, TAM_A) / TAM_A;
    mediageral[1] = soma(TurmaB, TAM_B) / TAM_B;
    mediageral[2] = soma(TurmaC, TAM_C) / TAM_C;
    mediageral[3] = soma(TurmaD, TAM_D) / TAM_D;

    insertion(mediageral);
    printf("\n");
    for (int i = 0; i < T; i++)
    {
        printf("%f ", mediageral[i]);
    }
    selection(mediageral, T);
    printf("\n");
    for (i = 0; i < T; i++)
    {
        printf("%f ", mediageral[i]);
    }
    quick(mediageral, 0, T - 1);
    printf("\n");
    for (i = 0; i < T; i++)
    {
        printf("%f ", mediageral[i]);
    }
    mergeSort(mediageral, 0, T - 1);
    printf("\n");
    for (i = 0; i < T; i++)
    {
        printf("%f ", mediageral[i]);
    }

    return 0;
}
