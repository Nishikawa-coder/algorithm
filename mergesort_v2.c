#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10000000

void merge_sort(long *S, int left, int right);
void merge(long *S,int left, int right);

int main(void){
int i,j;
    
    long *S;
    S=(long*)malloc(sizeof(long)*n);

    srand((unsigned)time(NULL));
    for(j=0;j<n;j++){
        S[j]=(32768*rand()+rand())%n+1;
    }
    printf("元:");
    for(i=0;i<n;i++){
        printf("%3ld,",S[i]);
    }
    printf("\n");
    merge_sort(S,0,n-1);
    printf("後:");
    for(i=0; i<n; i++){
        printf("%3ld,",S[i]);
    }
    printf("\n");
    free(S);

    long cpu_time;
    double sec;
    cpu_time=clock();
    sec=(double)cpu_time/CLOCKS_PER_SEC;
    printf("%f秒\n",sec);


    return 0;
}

void merge_sort(long *S, int left, int right){

    int mid=(right+left)/2;
    if(left<right){
    merge_sort(S,left,mid);
    merge_sort(S,mid+1,right);
    merge(S,left,right);
    }
}

void merge(long *S,int left, int right){
    int i;
    int mid=(right+left)/2;
    long *L,*R;
    int sizeL=mid-left+1;
    int sizeR=right-mid;
    L=(long *)malloc(sizeof(long)*sizeL);
    R=(long *)malloc(sizeof(long)*sizeR);

    for(i=0;i<sizeL;++i){
        L[i]=S[left+i];
    }
    for(i=0;i<sizeR;++i){
        R[i]=S[mid+i+1];
    }

    int j=1,k=1;
    for(i=1;i<=sizeL+sizeR;i++){
        if(j>sizeL){
            S[left+i-1]=R[k-1];
            k=k+1;
        }else if(k>sizeR){
            S[left+i-1]=L[j-1];
            j=j+1;
        }else if(R[k-1]>L[j-1]){
            S[left+i-1]=L[j-1];
            j=j+1;
        }else{
            S[left+i-1]=R[k-1];
            k=k+1;
        }
    }
    free(L);
    free(R);

    



}

