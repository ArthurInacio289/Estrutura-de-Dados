#include <stdio.h>
#define T 10

void insertion(int *a)
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

int main(int argc, char const *argv[])
{
    int V[T] = {2, 4, 5, 67, 4, 5, 6, 7, 4, 5};
    for (int i = 0; i < T; i++)
    {
        printf("%d ", V[i]);
    }
    insertion(V);
    printf("\n");
    for (int i = 0; i < T; i++)
    {
        printf("%d ", V[i]);
    }

    return 0;
}
