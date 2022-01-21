/*Place code here.*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

   if(argc < 2) { /*ARGC IS HERE*/
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
   }
   
   char x; //Current Character
   int accum = 0; //Accumulator
   
   for(int i =1; i<argc; i++) { //Loop through files
   FILE *fp = fopen(argv[i], "r");
   
   if(fp == NULL) { //NULL File
         exit(1);
   }
   
   while (fread(&accum, sizeof(int), 1, fp)==1) { //read file
   x = fgetc(fp); //Get character
   for(int numChar = 0; numChar < accum; numChar++) { //Print out current character based on accumulator
   printf("%c",x);
   }
 }
 
 fclose(fp);
 
}
exit(0);
}
