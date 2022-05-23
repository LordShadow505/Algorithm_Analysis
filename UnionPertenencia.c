#include<stdio.h>

int FindRoot(int P[], int x){

    while(P[x]= x){
        x = P[x];
    }
    return x;
}
int FindSet(int P[], int x, int y){

    return FindRoot(P, x) == FindRoot(P, y);
}

int Union(int P[], int x, int y){
    if (FindSet(P, x, y))
    {
        return 0;
    }

    int RootX = FindRoot(P, x);
    int RootY = FindRoot(P, y);
    if (RootY != RootX)
    {
        P[RootX] = RootY;
    } 
}

void MakeSet(int P[], int N){
   for (int i = 0; i < N; i++)
    {
        P[i] = i;
    }
}

int Imprimir(int P[], int N){
    for (int i = 0; i < N; i++)
    {
        printf("%d %d", P[i], i);
        printf("\n");
    } 
}

int main(){
    int N, M;
    int X, Y;

    char o;
    scanf("%d %d", &N, &M);
    int P[N];
    MakeSet(P, N);
    //Imprimir(P, N);
    for (int i = 0; i < M; i++)
    {
        scanf("%c %d %d", &o, &X, &Y);
        if (o == 'U')
        {
            Union(P, X, Y);
           // Imprimir(P, N);
        }
        else
        {
            (FindSet(P, X, Y));
            printf("%d\n", FindSet(P, X, Y));
        }
    }

    return 0;
}
