#include<stdio.h>
#include<string.h>

#define Max 45000
#define max(a,b) (((a) > (b)) ? (a) : (b))

char Palabra1[Max+1], Palabra2[Max+1];

long SubLarga (char *Palabra1, char *Palabra2)
{
    long i, j, Long1, Long2;
    long ColActual[Max+1], ColAnterior[Max+1];

    Long1 = strlen(Palabra1);
    Long2 = strlen(Palabra2);

    memset(ColActual, 0, sizeof(ColActual));
    for (i = 1; i <= Long1; i++)
    {
        memcpy(ColAnterior, ColActual, sizeof(ColAnterior));
        for (j = 1; j <= Long2; j++)
        ColActual[j] = (Palabra1[i-1] == Palabra2[j-1]) ?
        (ColAnterior[j-1] + 1) : (max(ColAnterior[j], ColActual[j-1]));
    }
    return (ColActual[Long2]);

}

int main()
{
    scanf("%s", Palabra1);
    scanf("%s", Palabra2);
    printf("%ld", SubLarga(Palabra1, Palabra2));
    return 0;
}