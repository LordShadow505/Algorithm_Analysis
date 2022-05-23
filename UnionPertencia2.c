#include<stdio.h>

int FindRoot(int P[], int x){
    while(P[x]!=x){
       x=P[x];
    }
    return x;
}

int FindSet(int P[], int x, int y){
    return FindRoot(P,x)==FindRoot(P,y);
}

int Union(int P[], int x, int y){
    int px=FindRoot(P,x);
    int py=FindRoot(P,y);      
    if(py!=px){
       P[px]=py;
    }
}

void MakeSet(int P[], int n){
    for(int i=0;i<n;i++)
        P[i]=i;
}

int print(int P[], int n){
    for(int i=0;i<n;i++)
        printf("(%d %d)",P[i], i);
    printf("\n");
}
int main(){
    int n, m, x, y;
    char o;
    scanf("%d %d", &n, &m);
    int P[n];
    MakeSet(P,n);
    for(int i=0;i<m;i++){ 
        //printf("%d\n", i);
        scanf(" %c %d %d", &o, &x, &y);
        if(o=='U'){
             Union(P,x,y);
	}
	else{
	  printf("%d\n", FindSet(P,x,y));
        }
    }
    return 0;

}
