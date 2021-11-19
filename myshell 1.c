#include <stdlib.h>
#include <string.h>
int main(){
while(1){
   int i,j,satir,sutun;
   char token[10][20];
   int dizi[50];
   printf("Myshell>>");
   char komut[150];
   gets(komut);
   sutun=0;
   satir=0;
   i=0;
   while(komut[i]!='\0'){
   	if(komut[i] == '|'){
   	siraliKomut=1;
   	}
   }
   if(siraliKomut){
   siraliKomut();
   }
  if(siraliKomut==0){
  tekliKomut();
  }
  //siraliKomut fonksiyonu için
  while(komut[i]!='\0'){
   	if(komut[i] != '|'){
   		token[satir][sutun]=komut[i];
   		sutun++;
   	}
   	else{   sutun++;
   		token[satir][sutun]='|';
   		sutun=0;
   		satir++;
   	}
   	i++;
   }
  sutun++; 
  token[satir][sutun]='|';
  satir++;
  sutun++;
  for(i=0; i<satir; i++){
  	for(j=0; j<sutun; j++){
  	printf("%s",token[j]);
  	}
  printf("\n");
  }
  }
return 0;

}





