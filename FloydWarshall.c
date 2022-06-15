#include <stdio.h>
#define inf 99999

void ImprimirMatriz(int n, int A[][n+1])
{
    // Imprime la matriz A

	int i,j;
	for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(A[i][j]==99999)
				printf("inf\t", A[i][j]);
			else
				printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

void ImprimirCamino(int n, int P[][n+1], int i, int j)
{
    // Imprime el camino de i a j
	if(P[i][j]==-1)
	{
		printf(" %d",j);
		return;
	}
	ImprimirCamino(n,P,i,P[i][j]);
	printf("-->%d",j);
}

void Warshall (int n, int W[][n+1], int P[][n+1]) 
{
    // Calcula el camino mas corto entre todos los pares de nodos
	int i, j, k;
    int x = 0;
	for (k = 1;k <= n;k++)
    {
        x++;
        for (i = 1;i <= n;i++)
        {         
            for (j = 1;j <= n;j++)
            {
                if (W[i][k] != inf && W[k][j] != inf && W[i][k] + W[k][j] < W[i][j])
                {
                    W[i][j] = W[i][k] + W[k][j];
                    P[i][j] = P[k][j];
                }
                
            }
        }
        
        printf("\nMatriz W%d \n", x);
 		ImprimirMatriz(n,W);
        
    }
    
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(i!=j)
			{               
				printf("\nCamino de %d a %d:",i,j);
				ImprimirCamino(n,P,i,j);
			}
		}
	}
	
}

int main()
{
	int i,e,j,k,w,n;
    printf("\n\n========================================================\n");
    printf("\n       PROGRAMA PARA CALCULAR CAMINOS MINIMOS\n");
    printf("                  FLOYD-WARSHALL\n");
    printf("\n========================================================\n\n");

	printf("Introducir el número de vertices:");
	scanf("%d",&n);

	printf("\nIntroducir el número de conexiones:");
	scanf("%d",&e);

    int b[n+1][n+1],p[n+1][n+1];
    for (i = 1; i <= n; i++)
    {
    	for (j = 1; j <= n; j++)
    	{
    		if(i==j)
    			b[i][j] = 0;
    		else
				b[i][j] = inf;
    		
    		p[i][j] = -1;
		}
	}
	for (i = 0; i < e; i++)
    {
        printf("\nIntroducir el camino y su peso ('De' 'A' 'Peso'):\n");
        printf("De->A Peso:\n ");
        scanf("%d %d %d",&j, &k, &w);
        b[j][k]=w;
        p[j][k]=j;
    }
    printf("\n\n========================================================\n\n");
    printf("\n       ITERACIONES DEL ALGORITMO FLOYD-WARSHALL:\n");
    printf("\n\n========================================================\n\n");
   	Warshall (n, b, p);
    printf("\n\n========================================================\n\n");
    return 0;
}
