/*Place code here.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   
   if(argc < 2) { /*ARGC IS HERE */
   	printf("wzip: file1 [file2 ...]\n");
   	exit(1);
   }
   
int accum =0;
char x;
char x2;

for(int i=1; i< argc; i++){

FILE *fp = fopen(argv[i], "r");
if(fp == NULL) {
   exit(1);
}


if (accum == 0) {
   fscanf(fp, "%c", &x); //Scanning for character in file to check
   accum =1;
   }
   
   while(fscanf(fp, "%c", &x2) != EOF) {
   
     if(x==x2) { //Check if same character
     accum++;
     }
     
     else { //Different Character
     fwrite(&accum, sizeof(int), 1, stdout);
     fwrite(&x, sizeof(char), 1, stdout);
     x=x2;
     accum =1;
     }
    }
     fclose(fp);
 }
     
     if(accum>0) {
     fwrite(&accum, sizeof(int), 1, stdout);
     fwrite(&x, sizeof(char),1, stdout);
     }
     
     exit(0);
   }
  
