#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>
#include <sys/wait.h>

void komutCalistir(char komut[]){
//burda dizi elemaný gönderdiðimiz için pass by reference oluyor ve komutlar dizisindeki elemanlar bozuluyor bu yüzden fonksiyonda gelen stringi bir baþka stringte tutmalýyým.
	char temp[strlen(komut)];
	strcpy(temp,komut);
	int i,sayac;
	i=0;
	sayac=0;
	//Burda bþluk ekliyorum çünkü gelen komutu boþluða göre ayýrýyorum. Ne kadar boþluk o kadar kelime demek eðer sonuna boþluk eklemessem 
	//hem ls,cat gibi direkt girilen komutlarý ayýramam, hemde komutlar boþluk sayýsý kadar kelimeden oluþuyor.
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
		printf("Program sonlandiriliyor... \n",tokenler[0]);
		exit(0);
		
	}
	else if(strcmp(tokenler[0],"bash")==0){
		int i,f;
		f=fork();
		if(f == 0){
			i=execve("/bin/bash",NULL,NULL);
			perror("Error: \n");
		}
		else{
			wait(&i); 
		}		
	}
	else if(strcmp(tokenler[0],"tekrar")==0){

		int f,i;
	
		if(!isdigit(tokenler[2][0])){
			printf("Lutfen tekrar komutunda kelimeden sonra bir sayi giriniz.\n");
		}
		else if(!isalpha(tokenler[1][0])){
			printf("Lutfen tekrar komutundan sonra bir kelime giriniz.\n");
		}
		
		else{	
			char *newargv[3];
			newargv[0]=tokenler[1];
			newargv[1]=tokenler[2];
			newargv[2]=NULL;
			f=fork();
			if(f == 0){
				i=execve("tekrar",newargv,NULL);
				perror("Error: ");
			}
			
		}	
	}
	else if(strcmp(tokenler[0],"islem")==0){
		int i,f,j,status;
		int hata=0;
		if((strcmp(tokenler[1],"topla")==0) || (strcmp(tokenler[1],"cikar")==0)  ){
			for(i=0; tokenler[2][i] != '\0'; i++){
				if(!isdigit(tokenler[2][i])){
					hata=1;
				}
			}
			for(i=0; tokenler[3][i] != '\0'; i++){
				if(!isdigit(tokenler[3][i])){
					
					hata=1;
				}
			}
			if(hata){
				printf("Lutfen topla veya cikardan sonra 2 adet sayiyi bosluk ile giriniz.\n");
				
			}
			else{
				char *newargv[4];
				newargv[0]=tokenler[1];
				newargv[1]=tokenler[2];
				newargv[2]=tokenler[3];
				newargv[3]=NULL;
				f=fork();
				if(f == 0){
					i=execve("islem",newargv,NULL);
					perror("Error:");
					}
					else{
						wait(&status);
						if(WIFEXITED(status))
							printf("islem sonucu= %d\n",WEXITSTATUS(status));
					}
			}
		}
		else {
			printf("Islem komutu sadece topla ve cikar ile kullanilabilir.\n");
		}
	}
	else if(strcmp(tokenler[0],"cat")==0){
		int f,i;
		char *newargv[3];
		newargv[0]=tokenler[0];
		newargv[1]=tokenler[1];
		newargv[2]=NULL;
		f=fork();
		if(f == 0){
			i=execve("/bin/cat",newargv,NULL);
			perror("Error: ");
		}
		else{
			wait(&i); 
		}	
			
		
	}
	else if(strcmp(tokenler[0],"clear")==0){
		int i,f;
		f=fork();
		if(f == 0){
			system("clear");
		}
		else{
			wait(&i); 
		}		
	
	}
	
	else if(strcmp(tokenler[0],"ls")==0){
		int i,f;
		char *newargv[2];
		newargv[0]="ls";
		newargv[1]=NULL;
		f=fork();
		if(f == 0){
			i=execve("/bin/ls",newargv,NULL);
			perror("Error: ");
		}
		else{
			wait(&i); 
		}	
		
	}
	else{
		printf("Komut bulunmadi. \n");
	}
	
}
int main(){
	while(1){
   	int i,j,sayac;
   	printf("Myshell>>");
   	char komut[150];
   	gets(komut);
   	//Komutlarý çizgiye göre ayýrdýðýmdan ötürü son komutuda ayýrabilmek için çizgi ekledim sonuna
   	const char s[2] = "|";
   	strncat(komut,s,1);
   	i=0;
   	sayac=0;
   	//kaç tane çizgi varsa o kadar komutum, kaçtane komutum varsa o kadar dizi için yer ayýrýyorum(komutlar dizi)
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
		//Burda dizide tutuyorum çünkü ayýrýp direkt fonksiyona yollayýnca kalan komutlar gitmiyor.
		komutlar[i]=token;
		token=strtok(NULL,s);
		i++;
	}
	
	for(i=0; i<sayac; i++){
		komutCalistir(komutlar[i]);
	}
	}
return 0;
}









