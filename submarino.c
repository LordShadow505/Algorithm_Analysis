#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int label;
    struct nodo *sig;
    int profundidad;

} nodo;

typedef struct cola{
    nodo *frente;
    nodo *final;
    int tam;

} cola;

void InsertaCola(cola *Q, int label)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->label = label;
    nuevo->sig = NULL;

    if(Q->tam == 0)
    {
        Q->frente = nuevo;  
    }

    else
    {
        Q->final->sig = nuevo;
    }
    Q->final = nuevo;
    Q->tam++;
    
}

int BorraCola(cola *Q)
{
   
    int d = -1;
    if(Q->tam == 0)
    {
        printf("Cola vacia\n");
    }
    
    else
    {
        nodo *aux = Q->frente;
        
        if (Q->tam == 1){
            Q->frente = NULL;
            Q->final = NULL;
        }
        else{
            Q->frente =  Q->frente ->sig;
        }
        aux -> sig = NULL;
        free(aux);
        Q->tam--;
    
    }
}

void Imprimir(cola *Q)
{

    nodo *aux = Q->frente;
   
    for (int i =0; i < Q -> tam ; i++)
    {
        printf("%d-> ", aux->label);
        aux=aux->sig;
    }
    printf("|\n");
}


int main()
{
    int N, E, T;
    scanf("%d %d %d", &N, &E, &T);
    cola G[N];
    for (int i = 0; i < N; i++)
    {
        //G[i] = (cola) {NULL, NULL, 0};
        G[i].frente = NULL;
        G[i].final = NULL;
        G[i].tam = 0;
    }
    for (int i = 0; i < E; i++)
    {
        int s, l;
        scanf("%d %d", &s, &l);
        InsertaCola(&G[s -1], l);
        InsertaCola(&G[l -1], s);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d: ", i);
        Imprimir(&G[i]);
    }
    return 0;

    /*
    int N, E, T;
    scanf("%d %d %d", &N, &E, &T);
    cola *G[N];
    */


    /*
    for (int i = 0; i < N; i++)
    {
        G[i] = (cola*)malloc(sizeof(cola));
        G[i]->frente = NULL;
        G[i]->final = NULL;
        G[i]->tam = 0;
        
    }
    for (int i = 0; i < E; i++)
    {
        int s, l;
        scanf("%d %d", &s, &l);
        InsertaCola(G[s-1], l);
        InsertaCola(G[l-1], s);
    }

    for (int i = 0; i < T; i++)
    {
        int s, l;
        scanf("%d %d", &s, &l);
        InsertaCola(G[s-1], l);
        InsertaCola(G[l-1], s);
    }
    for (int i = 0; i < N; i++)
    {
        Imprimir(G[i]);
    }
    */
    return 0;
}
    

    /*
    cola *Q = (cola*)malloc(sizeof(cola));
    Q->frente = NULL;
    Q->final = NULL;
    Q->tam = 0;

    InsertaCola(Q, 3);
    InsertaCola(Q, 2);
    InsertaCola(Q, 1);
    Imprimir(Q);

    while(Q->tam > 0)
    {
        BorraCola(Q);
        Imprimir(Q);
    }
    */
    
