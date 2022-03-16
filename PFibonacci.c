#include <stdio.h>

int main() 
{

	int N, i;
	int Fibonacci[100];
	int pos = -1;
	
    Fibonacci[1] = Fibonacci[2] = 1; //Iniciar los dos primeros numeros

		for(i=3; i<100; i++)
			{
			Fibonacci[i] =  Fibonacci[i-1] +  Fibonacci[i-2]; //Formula fibonacci
			}

    scanf("%d", &N);

		for(i=1; i<100; i++)
			{
				if(N ==  Fibonacci[i])
				{

				pos = i;
				break;
				
				}
			}

    printf("%d\n", pos);

	return 0;
}