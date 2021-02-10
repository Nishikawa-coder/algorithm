#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100

void merge_sort(long *S, int left, int right);
void merge(long *S,int left, int right);

int main(void){
int i,j;
    
    long *S;//メモリを確保し、用意しておいたポインタに先頭アドレスをいれるポインタを宣言する
    S=(long*)malloc(sizeof(long)*n);

    srand((unsigned)time(NULL));//発生する乱数がいつも異なるようにする

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

    long cpu_time;//計算時間を出力
    double sec;
    cpu_time=clock();
    sec=(double)cpu_time/CLOCKS_PER_SEC;
    printf("%f秒\n",sec);


    return 0;
}

void merge_sort(long *S, int left, int right){

    int mid=(right+left)/2;
    if(left<right){
    merge_sort(S,left,mid);//入力された配列の左側についてmergesortする
    merge_sort(S,mid+1,right);//入力された配列の右側についてmergesortする
    merge(S,left,right);//leftからrightまでの要素の値をmergeで合併する
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
        L[i]=S[left+i];//入力された配列の一部分の左側を配列Lにいれる。
    }
    for(i=0;i<sizeR;++i){
        R[i]=S[mid+i+1];//入力された配列の一部分の右側を配列Rにいれる。
    }

    int j=1,k=1;
    for(i=1;i<=sizeL+sizeR;i++){
        if(j>sizeL){//Lの要素を全てSに入れ終えた場合
            S[left+i-1]=R[k-1];//Rの要素を全てSにいれる
            k=k+1;
        }else if(k>sizeR){//Rの要素を全てSに入れ終えた場合
            S[left+i-1]=L[j-1];//Lの要素を全てSにいれる
            j=j+1;
        }else if(R[k-1]>L[j-1]){//Lの要素とRの要素を比較して大きい方をSにいれる
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

