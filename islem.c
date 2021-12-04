#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

int main(int argc, char *argv[], char *envp[]) {
	int i,f,j,sonuc;
	int fd[2];
	const char s1[2] = " ";
   	int toplam=(strlen(argv[1])+1)+(strlen(argv[2])+1);
	char sayi1[strlen(argv[1])+1];
	strcpy(sayi1,argv[1]);
	strncat(sayi1,s1,1);
	char sayi2[strlen(argv[2])];
	strcpy(sayi2,argv[2]);
	strncat(sayi2,s1,1);
	// 3 read;
	//4 write;
	strcat(sayi1,sayi2);
	if(pipe(fd)<0){
	perror("topla hatasi");
	exit(1);
	}
	if(strcmp(argv[0],"topla")==0){
	f=fork();
		if(f==0){
	
			i=execve("topla",NULL,NULL);
			perror("topla hatasi");
		}
		else{	
			int j;
			char s[1000];
			write(4,sayi1,toplam);
			close(4);
			wait(&i);
			j=read(3,s,1000);
			s[j]='\0';
			close(3);
			sonuc=atoi(s);
		}
	
	}
	else if(strcmp(argv[0],"cikar")==0){
	f=fork();
		if(f==0){
	
			i=execve("cikar",NULL,NULL);
			perror("cikar hatasi");
		}
		else{	
			int j;
			char s[1000];
			write(4,sayi1,toplam);
			close(4);
			wait(&i);
			j=read(3,s,1000);
			s[j]='\0';
			close(3);
			sonuc=atoi(s);
			
		}
	
	}
	printf("dönmezde");
	printf("sonuc: %d",sonuc);
	
return sonuc;
}
