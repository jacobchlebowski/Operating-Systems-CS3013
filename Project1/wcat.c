/*Place code here.*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

  
  
   for(int i=1; i<argc; i++){  //iterate through list of files
        FILE *fp = fopen(argv[i],"r"); //file at index i
        char bound[100];

        
    	if(fp==NULL){  
   	 printf("wcat: cannot open file\n");     //check NULL
    	exit(1);
  	}
  	
  	
  	//NULL CASE in if statement
  	if(fp!=NULL) {       //Not NULL -> use fgets() to read file until NULL
  	while( (fgets(bound,100, fp)) != NULL) {  
  	 printf("%s",bound);
  	 }
       }
   
   fclose(fp); //close file i
  }

exit(0);
}
