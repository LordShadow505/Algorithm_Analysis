#include <stdio.h>

int BusquedaBinaria(int A[], int min, int max, int x)
{
    if(max>=min){
        int m=(max+min)/2;

        if(A[m]==x)
            return m;
        
        else if(A[m]>x){
            return BusquedaBinaria(A,min,m-1,x);
        }
            return BusquedaBinaria(A,m+1,max,x);
        }
    
    return -1;

}

int A[100000];

int main()
{
  
    int M,N,x;

    scanf("%d", &M);    
        for(int i=0;i<M;i++)
        {
            scanf("%d",&A[i]);
        }

    scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x);
            printf("%d ",BusquedaBinaria(A,0,M-1,x)+1);
        }
        return 0;
}