#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

int main(){
		int i,sayi1,sayi2,toplam;
		char s[1000];
		const char s1[2] = " ";
		i=read(3,s,1000);
		s[i]='\0';
		close(3);
		i=0;
		char *tokenler[2];
		char *tokencik;
		tokencik=strtok(s,s1);
		i=0;
		while(tokencik != NULL){
		tokenler[i]=tokencik;
		tokencik=strtok(NULL,s1);
		i++;
		}
		sayi1=atoi(tokenler[0]);
		sayi2=atoi(tokenler[1]);
		toplam = sayi1+sayi2;
		sprintf(s,"%d",toplam);
		write(4,s,1000);
		toplam=0;
		close(4);
		close(3);
		
return 0;
}
