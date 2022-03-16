#include <stdio.h>

int main() 
{
    int N, M;
    scanf("%d %d", &N, &M);

    int X = N+M;
    int a[N], b[M], c[X];
    int i; 
    int x = 0, y = 0;
    int temp = 0;

        for (i=0; i<N; i++) 
            {
                scanf("%d", &a[i]);
            }
        
        for (i=0; i<M; i++) 
            {
                scanf("%d", &b[i]);
            }   
        
        
        //Mezcla a y b
        for (i=0; i<X; i++) 
        {
            if (i>N-1) 
            { 
                c[i] = b[y];
                y++;
            }
            
            else 
            {
                
                c[i] = a[i];
            }
            
        }
        
        //Ordena
        for (i=0; i<X; i++) 
        {
            for (x=i+1; x<X; x++) 
            {
                if (c[i] >= c[x]) 
                { 
                    temp = c[i];
                    c[i] = c[x];
                    c[x] = temp;
                }
            }
        }
        
        for (i=0; i<X; i++) 
        {
            printf("%d ", c[i]);
        }
        
    return 0;
}