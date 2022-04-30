#include <stdio.h>

int main()
{
	int K_Poste, N_Postes, k, AlaturaMenor = 1000000;
	scanf("%d", &K_Poste);
	scanf("%d", &N_Postes);

	int AlturaPoste[N_Postes];
	for (int i = 0; i < N_Postes; i++)
	{
		scanf("%d", &AlturaPoste[i]);
	}

	// ordenar basico
	for (int i = 0; i < N_Postes; i++)
	{
		for (k = 0; k < N_Postes - i - 1; k++)
		{
			if (AlturaPoste[k] > AlturaPoste[k + 1])
			{
				int aux = AlturaPoste[k];
				AlturaPoste[k] = AlturaPoste[k + 1];
				AlturaPoste[k + 1] = aux;
			}
		}
	}

	for (int i = 0, k = K_Poste - 1; i < N_Postes - K_Poste; i++, k++)
	{
		if (AlturaPoste[k] - AlturaPoste[i] < AlaturaMenor)
		{
			AlaturaMenor = AlturaPoste[k] - AlturaPoste[i];
		}
	}
	printf("%d", AlaturaMenor);
	return 0;
}
