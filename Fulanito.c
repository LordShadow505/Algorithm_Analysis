#include <stdio.h>
#include <stdlib.h>

int Auto,Auto2;
int Calcular(int x, int y,int *a){
    for(int z=x;z<x+2;z++){
        if(z%2==0)
            a[z]=y;
        else
            a[z]=Auto-Auto2;
    }
}

int main()
{
    int n,m;
    scanf("%i%i",&n,&m); n*=2;

	int* a = malloc(n-1*sizeof(*a));
	int* g = malloc(m-1*sizeof(*g));
    

    for(int x=0;x<m;x++)
	{
        scanf("%i",&g[x]);
	}
    for(int x=0;x<n;x+=2)
	{
        Auto2=0; scanf("%i",&Auto);
        for(int y=0;y<m;y++)
		{
            if(Auto2+g[y]<=Auto)
			{
                Auto2+=g[y];
                if(y+1==m)
				{
                    Calcular(x,y+1,a);
                }
            }
				else
			{
                Calcular(x,y,a);
                break;
            }
        }
    }

    for(int x=0;x<n;x+=2)
	{
        printf("%i %i\n",a[x],a[x+1]);

	}
	
    return 0;
}