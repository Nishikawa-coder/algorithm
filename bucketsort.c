#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 12 //要素数
#define m 5 //バケツの数

struct cell{//構造体の定義
    int index;
    struct cell*next;
};

void bucket_sort(int A1[],int A2[]);

int main(void){
    int i,A1[n],A2[n];
    long cpu_time;

    srand((unsigned)time(NULL));//発生する乱数がいつも異なるようにする

    for(i=0; i<n; i++)
        A1[i]=rand()%m;

    printf("元: ");
    for(i=0; i<n; i++)
        printf("%2d ",A1[i]);

    bucket_sort(A1,A2);

    printf("\n後: ");

    for(i=0; i<n; i++)
        printf("%2d ",A2[i]);

    printf("\n");

    return 0;

}

void bucket_sort(int A1[],int A2[]){
    struct cell *B[m], *p, *Bj;
    int i,j;

    for(j=0; j<m; j++)
        B[j]=NULL;//B[j]のアドレスにNULLを代入

    for(i=0; i<n; i++){
        p=(struct cell *)malloc(sizeof(struct cell));//メモリ領域を取得
        p->index=i;
        p->next=B[A1[i]];//p.nextにB[A1[i]]のアドレスを代入
        B[A1[i]]=p;//B[A1[i]]のアドレスにpのアドレスを代入
    }

    i=n-1;
    for (j=m-1; j>=0; j--){
        Bj=B[j];
        while(Bj!=NULL){
            A2[i]=A1[Bj->index];//Bj.indexを要素番号にしたA1の要素値をA2に代入する
            i--;
            Bj=Bj->next;
        }
    }


}

