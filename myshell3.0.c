#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void komutCalistir(char komut[]){
	
	char temp[strlen(komut)];
	strcpy(temp,komut);
	int i,sayac;
	i=0;
	sayac=0;
	const char s1[2] = " ";
   strncat(temp,s1,1);
   while(temp[i] != '\0'){
   	if(temp[i] == ' '){
   	sayac++;
   	}
   	i++;
   }
    char *tokenler[sayac];
	char *tokencik;
	tokencik=strtok(temp,s1);
	i=0;
	while(tokencik != NULL){
		tokenler[i]=tokencik;
		tokencik=strtok(NULL,s1);
		i++;
	}
	if(strcmp(tokenler[0],"exit")==0){
		printf("%s caliscak",tokenler[0]);
	}
	else if(strcmp(tokenler[0],"bash")==0){
			printf("%s caliscak",tokenler[0]);
	}
	else if(strcmp(tokenler[0],"tekrar")==0){
		printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"islem")==0){
			printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"cat")==0){
			printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"clear")==0){
			printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"ls")==0){
			printf("%s caliscak",tokenler[0]);
		
	}
	
}
int main(){
while(1){
   int i,j,sayac;
   printf("Myshell>>");
   char komut[150];
   gets(komut);
   const char s[2] = "|";
   strncat(komut,s,1);
   i=0;
   sayac=0;
   while(komut[i] != '\0'){
   	if(komut[i] == '|'){
   	sayac++;
   	}
   	i++;
   }
   i=0;
   char *komutlar[sayac];
	char *token;
	token=strtok(komut,s);
	while(token != NULL){
		komutlar[i]=token;
		token=strtok(NULL,s);
		i++;
	}
	//burda dizi elemanı gönderdiğimiz için pass by reference oluyor ve komutlar dizisi bozuluyor bu yüzden fonksiyonda gelen stringi bir başka stringte tutmalıyım.
	for(i=0; i<sayac; i++){
		komutCalistir(komutlar[i]);
	}
return 0;

}

}









