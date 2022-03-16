#include <stdio.h>
//CT

int main()
{
	int x;
    int n;
    int a[0], b[0];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
        scanf("%d",&b[i]);  
        }  

        for(int i=0;i<n;i++)
        {
        x = x + a[i] + b[i];
        }

    }

    

    
    printf("%d",x);
}
