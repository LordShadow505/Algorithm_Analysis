#include <stdio.h>

int main()
	{
	int ordenar;
	int lim = 0;
	scanf("%d", &lim);
	int num[lim];
	
	for (int i=0; i<lim; i++)
	{
    	scanf("%d",&num[i]);
	}

  //Ordenar
	for (int i=0; i<lim; i++)
	{
  		for (int j=0; j<lim - i - 1; j++)
  		{
    			if (num[j] < num[j+1])
    			{ 
      			ordenar = num[j];
      			num[j] = num[j+1];
      			num[j+1] = ordenar;
   			}
  		}	
	}

	
	for (int i = 0; i <= lim -1; i++)
	printf("%d\n", num[i]);


	return 0;
}