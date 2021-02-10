#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100

void QuickSort(int i,int j,long *A);
int verifysorted(int i,int j,long *A);
int pivot(int i,int j,long *A);
int partition(int i,int j,int p,long *A);


int main(void){
    int i,j;
    
    long *A;
    A=(long*)malloc(sizeof(long)*n);//メモリを確保し、用意しておいたポインタに先頭アドレスをいれるポインタを宣言する

    srand((unsigned)time(NULL));//発生する乱数がいつも異なるようにする

    for(j=0;j<n;j++){
        A[j]=rand()%(n+1);
    }

    printf("元:");
    for(i=0;i<n;i++){
        printf("%3ld,",A[i]);
    }
    printf("\n");
    
    QuickSort(0,n-1,A);
    
    printf("後:");
    for(i=0; i<n; i++){
        printf("%3ld,",A[i]);
    }
    printf("\n");
    free(A);

    long cpu_time;//計算時間を計る
    double sec;
    cpu_time=clock();
    sec=(double)cpu_time/CLOCKS_PER_SEC;
    printf("%f秒\n",sec);

    return 0;

}


void QuickSort(int i,int j,long *A){
     
    if(verifysorted(i,j,A)==1){
        int p=pivot(i,j,A);
        //printf("p=%d\n",p);
        int k=partition(i,j,p,A);
        QuickSort(i,k-1,A);
        QuickSort(k,j,A);
        
    }
}

int verifysorted(int i,int j,long *A){
    //Aの要素数が2未満、または全ての要素の値がソート済の場合は0,そうでない場合は1を出力する。
    int k;
    if(j-i+1<2)
        return 0;
    for(k=i; k<j; ++k)
        if(A[k]>A[k+1])
            return 1;
    return 0;
}

int pivot(int i,int j,long *A){
    //配列の軸要素を見つけて出力する。
    while(1){
        if(A[i]<A[i+1])
            return i+1;
        if(A[i]>A[i+1])
            return i;
            if(i+1==j)
            return -1;
        i++;
    }
    
}

int partition(int i,int j,int p,long *A){
    int L=i;
    int R=j;
    int pivot=A[p];
    int temp;
    int k;

    while(1){
        while(A[L]<pivot)
            L=L+1;
        while(A[R]>=pivot)
            R=R-1;
        if(L<R){
            temp=A[L];//change
            A[L]=A[R];
            A[R]=temp;
        }else
            return L;
    }

}



