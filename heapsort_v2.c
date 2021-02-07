#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100


void heapsorts(long *A);
void Insert(int x,long* H,int j);
long DeleteMin(long *H,int j);


int main(void){
    int i,j;
    long *A;
    A=(long*)malloc(sizeof(long)*n);

    srand((unsigned)time(NULL));//発声する乱数がいつも異なるようにする

    for(j=0;j<n;j++){
        A[j]=rand()%(n+1);
    }

    printf("元:");
    for(i=0;i<n;i++){
        printf("%3ld,",A[i]);
    }
    printf("\n");
    
    heapsorts(A);

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


void heapsorts(long *A){
    int i;
    long *H=NULL;
    H = (long *)malloc(sizeof(long)*n);//ヒープ木Hは親<=子の順になる
    
    for(i=0;i<n;++i){
        Insert(A[i],H,i);
    }
    for(i=n-1;i>=0;i--){
        A[n-1-i]=DeleteMin(H,i);
    }
    
    free(H);
}




void Insert(int x,long* H,int j){
    int p=(j-1)/2;//jの要素値の親の要素番号をpに代入

    if((j==0)||(H[p]<=x)){//jが0もしくは、親の値<=xの場合
        H[j]=x;
    }else{
        H[j]=H[p];
        Insert(x,H,p);
    }
}

long DeleteMin(long *H,int j){
    //H[0]にあった要素値を出力し、末尾の要素値をH[0]に代入して親<=子になるまで親と子を要素番号0から順に交換していく
    int c1=1,cr=2;//c1,crはそれぞれ左側の子右側の子
    int minx=H[0];
    H[0]=H[j];
    int c;//交換する対象
    int p=0;

    if(j<c1){//子がない場合
        c=j;
    }else if(j==c1){//子が左しかいない場合
        c=c1;
    }else{
        if(H[c1]<H[cr]){//左の子と右の子のどちらか小さい方をcに代入
            c=c1;
        }else{
            c=cr;
        }
        
    }
      
    while((c<j)&&(H[p]>H[c])){
        int temp=H[p];
        H[p]=H[c];
        H[c]=temp;
        //swap(H[p],H[c]);
        p=c;
        c1=2*p+1;
        cr=c1+1;
        if(j<c1){
            c=j;
        }else if(j==c1){
            c=c1;
        }else{
            if(H[c1]<H[cr]){
                c=c1;
            }else{
                c=cr;
            }
        
        }
    
    }
    return minx;
}



