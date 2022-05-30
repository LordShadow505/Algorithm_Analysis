#include<stdio.h>
int main (){

  //nxn matrix solver Ax = b

  int n;
  printf("Ingresa el tamaño de la matrix:\n");
  scanf("%d", &n);
  int i, j, k;
  double A[n][n], b[n], x[n];
  double sum;
  printf("Ingresa los valores de la matrix:\n");
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      scanf("%lf", &A[i][j]);
    }
  }
  printf("Ingresa los valores de b:\n");
  for (i = 0; i < n; i++){
    scanf("%lf", &b[i]);
  }
  for (i = 0; i < n; i++){
    sum = 0;
    for (j = 0; j < n; j++){
      sum += A[i][j] * b[j];
    }
    x[i] = sum;
  }
  for (i = 0; i < n; i++){
    printf("X=%.0lf\n", x[i]);
  }
  return 0;


  
}
