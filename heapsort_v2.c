#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10000000

//void swap(long x,long y)
void heapsorts(long *A);
void Insert(int x,long* H,int j);
long DeleteMin(long *H,int j);


int main(void){
    int i,j;
    long *A;
    A=(long*)malloc(sizeof(long)*n);

    srand((unsigned)time(NULL));
    for(j=0;j<n;j++){
        A[j]=rand()%(n+1);//
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
    long cpu_time;
    double sec;
    cpu_time=clock();
    sec=(double)cpu_time/CLOCKS_PER_SEC;
    printf("%f秒\n",sec);
    return 0;
}


/*void swap(long x,long y){
    long temp=x;
    x=y;
    y=temp;
}*/

void heapsorts(long *A){
    int i;
    long *H=NULL;
    H = (long *)malloc(sizeof(long)*n);
    
    for(i=0;i<n;++i){
        Insert(A[i],H,i);
    }
    for(i=n-1;i>=0;i--){
        A[n-1-i]=DeleteMin(H,i);
    }
    
    free(H);
}




void Insert(int x,long* H,int j){
    int p=(j-1)/2;
    if((j==0)||(H[p]<=x)){
        H[j]=x;
    }else{
        H[j]=H[p];
        Insert(x,H,p);
    }
}

long DeleteMin(long *H,int j){
    int c1=1,cr=2;
    int minx=H[0];
    H[0]=H[j];
    int c;
    int p=0;
    if(j<c1){//ここらへんの大小のかけ方がおかしかったので変えた
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
       /* if(2*p+2<=j){
            if(H[2*p+1]>H[2*p+2])
                c=2*p+2;
            else
                c=2*p+1;
        }else{
        c=2*p+1;
        }
    }else
        c=j+1*/
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



