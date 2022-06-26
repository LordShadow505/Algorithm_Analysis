#include <stdio.h>

int main(){

    int N, C, P_Peso, V_Valor, max;

    scanf("%d", &N);
    scanf("%d", &C);
    
    
    int matriz[N][2];
    for (int i = 0; i < N; i++){
        scanf("%d", &P_Peso);
        scanf("%d", &V_Valor);
        matriz[i][0] = P_Peso;
        matriz[i][1] = V_Valor;
    }

    int mochila[C + 1];
    for (int i = 0; i <= C; i++){
        mochila[i] = 0;
    }

    for (int i = 0; i < N; i++){
        for (int j = C; j >= matriz[i][0]; j--){
            if (mochila[j] < mochila[j - matriz[i][0]] + matriz[i][1])
                mochila[j] = mochila[j - matriz[i][0]] + matriz[i][1];
        }
    }
    max = mochila[C];
    printf("%d\n", max);
    
}

/*
5
4
4 4
1 3
3 2
9 5
1 3
*/