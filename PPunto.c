#include <stdio.h>

int main()
{
	int x;
    int n;
    int i = 0;
    int a[10];
    int b[10];

    scanf("%d", &n);

        for(i=0;i<n;i++)
            {
                scanf("%d", &a[i]); 
                a[i] =  a[i];
                
            }

        for(i=0;i<n;i++)
            {
                scanf("%d", &b[i]);  
            }  

        for(i=0;i<n;i++)
            {
                x = x + a[i] * b[i];
            }


        printf("%d",x);
        
    return 0;
}
