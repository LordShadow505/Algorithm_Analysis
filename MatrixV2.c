#include <stdio.h>
int main()
{

  int n, i, j, k, l;
  int L[10][10], U[10][10], A[10][10], b[10], x[10];
  int sum, sum1, sum2, sum3;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  printf("Enter the matrix A: \n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter the matrix b: \n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
  }

  // L matrix
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i == j)
      {
        L[i][j] = 1;
      }
      else
      {
        L[i][j] = 0;
      }
    }
  }

  // U matrix
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i == j)
      {
        U[i][j] = A[i][j];
      }
      else
      {
        U[i][j] = 0;
      }
    }
  }

  // L matrix
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i > j)
      {
        L[i][j] = A[i][j];
      }
    }
  }

  // U matrix
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i < j)
      {
        U[i][j] = A[i][j];
      }
    }
  }
  printf("The L matrix is: \n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", L[i][j]);
    }
    printf("\n");
  }
  printf("The U matrix is: \n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", U[i][j]);
    }
    printf("\n");
  }
  
  //solve x vector
  for (i = 0; i < n; i++)
  {
    sum = 0;
    for (j = 0; j < i; j++)
    {
      sum = sum + L[i][j] * x[j];
    }
    x[i] = (b[i] - sum) / L[i][i];
  }
  printf("The x vector is: \n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n");
  
  
}
