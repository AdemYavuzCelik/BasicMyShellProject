#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void komutCalistir(char komut[]){
	printf("\n komut: %s",komut);
	char temp[strlen(komut)];
	strcpy(temp,komut);
	printf("\n temp :%s",temp);
	int i,sayac;
	i=0;
	sayac=0;
	//Burda bşluk ekliyorum çünkü gelen komutu boşluğa göre ayırıyorum. Ne kadar boşluk o kadar kelime demek eğer sonuna boşluk eklemessem 
	//hem ls,cat gibi direkt girilen komutları ayıramam, hemde komutlar boşluk sayısı kadar kelimeden oluşuyor.
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
		exit(0);
		printf("%s caliscak",tokenler[0]);
	}
	else if(strcmp(tokenler[0],"bash")==0){
		
	}
	else if(strcmp(tokenler[0],"tekrar")==0){
		printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"islem")==0){
			printf("%s caliscak",tokenler[0]);
		
	}
	else if(strcmp(tokenler[0],"cat")==0){
		char *newargv[3];
		newargv[0]=tokenler[0];
		newargv[1]=tokenler[1];
		tokenler[2]=NULL;
		for(i=0; i<3 ; i++){
			printf("%s---",tokenler[i]);
		}
		/*
		int f,i,j;
		f=fork();
		if(f == 0){
			i=execve("/bin/cat",tokenler,NULL);
			perror("cat hatasi");
		}
		else{
			wait(&i); 
		}
		*/
		
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
   //Komutları çizgiye göre ayırdığımdan ötürü son komutuda ayırabilmek için çizgi ekledim sonuna
   const char s[2] = "|";
   strncat(komut,s,1);
   i=0;
   sayac=0;
   //kaç tane çizgi varsa o kadar komutum, kaçtane komutum varsa o kadar dizi için yer ayırıyorum(komutlar dizi)
   while(komut[i] != '\0'){
   	if(komut[i] == '|'){
   	sayac++;
   	}
   	i++;
   }
   i=0;
   //Burda dizide tutuyorum çünkü ayırıp direkt fonksiyona yollayınca kalan komutlar gitmiyor.
   char *komutlar[sayac];
	char *token;
	token=strtok(komut,s);
	while(token != NULL){
		printf("\n token: %s",token);
	
		komutlar[i]=token;
		token=strtok(NULL,s);
		i++;
	}
	//burda dizi elemanı gönderdiğimiz için pass by reference oluyor ve komutlar dizisindeki elemanlar bozuluyor bu yüzden fonksiyonda gelen stringi bir başka stringte tutmalıyım.
	for(i=0; i<sayac; i++){
			komutCalistir(komutlar[i]);
	}
return 0;

}

}









