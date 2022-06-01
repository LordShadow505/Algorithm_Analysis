#include <stdio.h>

int main()
{
    printf("======================================================\n");
    printf("      Calculadora de Matrices Ax = B       Método LU  \n");
    printf("                                                      \n");
    printf("        Carlos Alberto Tavera Arteaga - 1628839A      \n");
    printf("======================================================\n");

    int n, i, k, j, P;
    double A[100][100], L[010][100] = {0}, U[100][100] = {0}, sum, B[100], z[100] = {0}, x[100] = {0};

    printf("Introduce el tamaño de la matriz A\n");

    scanf("%d", &n);
    printf("Introduce los valores de la matriz A %d x %d:\n", n, n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nIntroduce los valores B:\n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%lf", &B[i]);
    }

    // Descomposicion LU

    for (k = 1; k <= n; k++)
    {
        U[k][k] = 1;
        for (i = k; i <= n; i++)
        {
            sum = 0;
            for (P = 1; P <= k - 1; P++)
                sum += L[i][P] * U[P][k];
            L[i][k] = A[i][k] - sum;
        }

        for (j = k + 1; j <= n; j++)
        {
            sum = 0;
            for (P = 1; P <= k - 1; P++)
                sum += L[k][P] * U[P][j];
            U[k][j] = (A[k][j] - sum) / L[k][k];
        }
    }

    // Mostrar matriz LU

    printf("\nMatriz L:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%lf ", L[i][j]);
        printf("\n");
    }
    printf("\nMatriz U:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%lf ", U[i][j]);
        printf("\n");
    }

    // Sustitucion hacia adelante

    for (i = 1; i <= n; i++)
    {
        sum = 0;
        for (P = 1; P < i; P++)
            sum += L[i][P] * z[P];
        z[i] = (B[i] - sum) / L[i][i];
    }

    // Calcular X

    for (i = n; i > 0; i--)
    {
        sum = 0;
        for (P = n; P > i; P--)
            sum += U[i][P] * x[P];
        x[i] = (z[i] - sum) / U[i][i];
    }

    printf("\nValores de X:\n");

    for (i = 1; i <= n; i++)
    {
        printf("x%d= %lf\n", i, x[i]);
    }
    printf("\n");
    printf("=====================================================\n");
    return 0;
}

/*
3 6 9
6 2 1
9 1 2
a
2 8 5
*/

