#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10000000

int main(){
    int i;
    /*printf("配列を入力してください\n");
    int a[n];
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }*///乱数にしていなかったので配列の中身の入力のみ書き直した↓

    long a[n];
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        a[i]=(32768*rand()+rand())%n+1;
    }
    
    printf("元:");
    for(i=0;i<n;i++){
        printf("%3ld,",a[i]);
    }
    printf("\n");
    //printf("%d",a[0]);
    int x,j;
    for(i=0; i<n-1; i++){
        for(j=n-1; j>i; j--){
            if(a[j]<a[j-1]) {
                x=a[j];
                a[j]=a[j-1];
                a[j-1]=x; //change
            }
        }
    }

    printf("後:");
    for(i=0; i<n; i++){
        printf("%3ld,",a[i]);
    }
    printf("\n");

    long cpu_time;
    double sec;
    cpu_time=clock();
    sec=(double)cpu_time/CLOCKS_PER_SEC;
    printf("%f秒\n",sec);
    
    return 0;
}