#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>
int main(int argc, char *argv[], char *envp[]) {
   int i,sayi;
   sayi=atoi(argv[1]);
   printf("%d",sayi);
   for(i=0; i<sayi; i++){
   	printf("%s\n",argv[0]);
   }
   return 0;
}
