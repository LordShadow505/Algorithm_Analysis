  #include <stdio.h>

int main()
	{
	int ordenar;
	int lim = 0;
	scanf("%d", &lim);
	int NCactus[lim];
	
	for (int i=0; i<lim; i++)
	{
    	scanf("%d",&NCactus[i]);
	}

  //Ordenar
	for (int i=0; i<lim; i++)
	{
  		for (int j=0; j<lim - i - 1; j++)
  		{
    			if (NCactus[j] < NCactus[j+1])
    			{ 
      			ordenar = NCactus[j];
      			NCactus[j] = NCactus[j+1];
      			NCactus[j+1] = ordenar;
   			}
  		}	
	}

	
	for (int i = 0; i <= lim -1; i++)
	printf("%d ", NCactus[i]);

    int NPreguntas = 0;

    scanf("%d", &NPreguntas);

    

    /*
5
2 7 1 8 3
4
3 1 4 1
    */

	return 0;
}
