#include <stdio.h>
#define MAX(a,b) (a>b?a:b)

int T[101][101];

int suma(int i, int j, int n){

    if(i==n-1){
        return T[i][j];
    }
    else{
        return T[i][j]+MAX(suma(i+1,j,n),suma(i+1,j+1,n));
    }
} 

int main()
{
    
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d", &T[i][j]);
        }
    }

    int max=0;
    for(int i=0;i<n;i++){
        max=MAX(max,suma(0,i,n));
    }
    printf("%d\n", max);

}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/