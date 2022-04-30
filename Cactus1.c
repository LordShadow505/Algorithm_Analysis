#include <stdio.h>

void QuickSort(int NCactus[], int Primer, int Ultimo)
{
	int i, j, CactusPivote, Temp;

	if (Primer < Ultimo)
	{
		CactusPivote = Primer;
		i = Primer;
		j = Ultimo;

		while (i < j)
		{
			while (NCactus[i] >= NCactus[CactusPivote] && i < Ultimo)
				i++;
			while (NCactus[j] < NCactus[CactusPivote])
				j--;
			if (i < j)
			{
				Temp = NCactus[i];
				NCactus[i] = NCactus[j];
				NCactus[j] = Temp;
			}
		}

		Temp = NCactus[CactusPivote];
		NCactus[CactusPivote] = NCactus[j];
		NCactus[j] = Temp;
		QuickSort(NCactus, Primer, j - 1);
		QuickSort(NCactus, j + 1, Ultimo);
	}
}

int main()
{
	int i, lim;

	//Leer el numero de cactus
	scanf("%d", &lim);	
	int NCactus[lim];

	//Leer alturas de cactus
	for (i = 0; i < lim; i++)
	{
		scanf("%d", &NCactus[i]);
	}
	//Ordenar los cactus usando QuickSort
	QuickSort(NCactus, 0, lim - 1);

	int NPreguntas = 0;

	//Leer el numero de preguntas
	scanf("%d", &NPreguntas);

	//Imprimir cactus de preguntas
	for (int i = 0; i < NPreguntas; i++)
	{
		int Pregunta;
		scanf("%d", &Pregunta);
		printf("%d ", NCactus[Pregunta - 1]);
	}

	return 0;
}

/*
5
2 7 1 8 3
4
3 1 4 1
*/
