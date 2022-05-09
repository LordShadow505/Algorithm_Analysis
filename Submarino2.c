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

void InsertaCola(cola *Q, int N)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->label = N;
    nuevo->sig = NULL;
    nuevo->profundidad = 0;

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

void InsertaColaProf(cola *Q, int N, int d)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->label = N;
    nuevo->sig = NULL;
    nuevo->profundidad = d;

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
    return 0;
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

void Imprimir2(cola *Q)
{
    nodo *aux = Q->frente;

    for (int i =0; i < Q -> tam ; i++)
    {
        printf("%d(%d)->", aux->label, aux -> profundidad);
        aux=aux->sig;
    }
    printf("\n");

}

void BFS(cola *G[], int s)
{
    int V[s+1], k, dp;
    cola *Q = (cola *)malloc(sizeof(cola));

    for(int i = 0; i < s+1; i++)
        V[i] = 0;
        InsertaCola(Q, s);
        V[s] = 1;
    
     while(Q->tam > 0)
     {
        Imprimir2(Q);
        nodo *act = Q->frente;
        k = act->label;
        dp = act->profundidad;
        BorraCola(Q);

            for (nodo *h = G[k]->frente; h != NULL; h=h->sig)
            {
                if(!V[h->label])
                {
                    //h -> profundidad = dp + 1;
                    InsertaColaProf(Q, h->label, dp+1);
                    V[h->label] = 1;
                }
            }
     }   
     printf("%d", dp -1);
}

int main()
{
    int N, E, T;
    int s, l;
    scanf("%d %d %d", &N, &E, &T);
    cola *G[N+1];
    for (int i = 0; i <= N; i++)
    {
        cola *Q = (cola *)malloc(sizeof(cola));
        Q->frente = NULL;
        Q->final = NULL;
        Q->tam = 0;
        G[i] = Q;
    }
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &s, &l);
        InsertaCola(G[s], l);
        InsertaCola(G[l], s);
    }

    for (int i = 0; i <= N; i++)
    {
        printf("G[%d]: ", i);
        Imprimir(G[i]);
    }

    printf("\n");
    BFS(G, N);

    return 0;
}
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
    
