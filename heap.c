#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int size;
    int *data;
    int max_size;
    } heap;
    

    int parent(int i)
    {
        return i/2;
    }

    int left (int i)
    {
        return 2*i;
    }

    int right (int i)
    {
        return 2*i+1;
    }

    

    //=======================================================
    //              Swap
    //=======================================================
    void swap(heap H, int i, int j)
    {
        int aux = H.data[i];
        H.data[i] = H.data[j];
        H.data[j] = aux;
    }



    //=======================================================
    //              Max Heapify
    //=======================================================
    void maxHeapify(heap H, int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l <= H.size && H.data[largest] > H.data[l])
            largest = l;

        if (r <= H.size  && H.data[largest] > H.data[r])
            largest = r;

        if(i!=largest)
        {
            swap(H, largest, i);
            maxHeapify(H, largest);
        }

    }



    //=======================================================
    //              Imprimir
    //=======================================================
    void print(heap H)
    {
        for(int i=1; i <= H.size; i++)
            printf("%d ", H.data[i]);
            printf("\n");
    }



    //=======================================================
    //              Costructor Max Heap
    //=======================================================
    void buildMaxHeap(heap H)
    {
        int i;
        for(i=H.size/2; i>0; i--){
            maxHeapify(H, i);
            print(H);
        }
            
    }



    //=======================================================
    //              Borrar Max
    //=======================================================
    int deleteMax(heap H)
    {
        int d = H.data[1];
        if (H.size >1)
        {
            swap(H,1,H.size);
            maxHeapify(H, 1);
            H.size--;
        }

        return d;
            
    }



    //=======================================================
    //              Main = 36 11 5 21 1 13 2 20 5 4 8 
    //=======================================================

    int main()
    {
        int i;
        int n;
        scanf("%d", &n);
        heap H;
        H.size = n;
        H.max_size = n +1;
        H.data = (int*) malloc((n+1)*sizeof(int));

        for(i=1; i<=n -1; i++)
        {
            scanf("%d ", &H.data[i]);
           // H.size++;
        }

        print(H);
        
        buildMaxHeap(H);

        print(H);

        deleteMax(H);

        print(H);

        return 0;
    }
