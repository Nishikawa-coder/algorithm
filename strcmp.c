#include<stdio.h>
//#include<string.h>

int main(void){
  char a[1000],b[1000];
  int i=0;
  scanf("%s",a);
  scanf("%s",b);
  
  while(a[i]!='\0'){
    //printf("%c",a[i]);
    i=i+1;
  }
  int aleng=i;//a配列の長さを代入
  i=0;
  while(b[i]!='\0'){
    //printf("%c",b[i]);
    i=i+1;
  }
  int bleng=i;//b配列の長さを代入(a配列の長さ>=b配列の長さである前提)
  //printf("%d %d",aleng,bleng);
  
  int n;
  n=aleng-bleng+1;
  
  int t[n],j,count;
  for(i=0;i<n;i++){
    count=0;
    for(j=i;j<i+bleng;j++){
      if(a[j]==b[j-i]) count+=1;//あっている回数だけcountに1たす
      //printf("a=%c b=%c\n",a[j],b[k]);
    }
   t[i]=count;//配列tにaとbの文字がどれだけ一致しているかの数字を入れていく。
   //printf("%d",t[i]);
      
  }
  
  int max=t[0];
  for(i=1;i<n;i++){
    if(t[i]>max) max=t[i];
  }
  
  
  printf("%d\n",aleng-max);//aを一文字ずつずらして一番修正数が少ないものを出力
  
  return 0;
}