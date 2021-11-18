#include <stdlib.h>

int main(){
   char token[10][20];
   int dizi[50];
   printf("Myshell>>");
   char komut[150];
   gets(komut);
   int i,j,k,bas,satir,sutun;
   j=0;
   for(i=0; komut[i]!='\0'; i++){
   	printf("%c",komut[i]);
   }
   printf("%c \n",komut[i]);
   for(i=0; i<150; i++){
   	if(komut[i] == '|'){
   		dizi[j]=i;
   		j++;
   	}
   }
   for(i=0; i<50; i++){
   	printf("%d-",dizi[i]);
   }
   printf("\n");
   bas=0;
   sutun=0;
   satir=0;
   i=0;
   j=0;
   
   while(dizi[j]!=0){
   	for(i=bas; i<dizi[j]; i++){
   		token[satir][sutun]=komut[i];
   		sutun++;
   		
   	}
   	sutun=0;
   	printf("%d",bas);
   	bas=dizi[j]+1; 
   	satir++;             
   	j++;           
               
   }
   
  for(i=0; i<10; i++){
  	printf("%s\n",token[i]);
  }
return 0;
}
