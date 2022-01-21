#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len =0;
    ssize_t nread=0;
    char bound[1024];
    
    
  if (argc < 2) { /* ARGC IS HERE */         //when user only puts in "wgrep"
  	printf("wgrep: searchterm [file ...]\n");
  	exit(1);
  }	
  
  if(argc == 2){     //user puts in "wgrep searchterm" but no file name
       while((nread = getline(&line, &len, stdin)) != -1){
             if(strstr(line, argv[1])) { /*ARGC IS HERE*/
             printf("%s",line);
     }
  }
exit(0); 
}

   for(int i=2; i<argc; i++){
     FILE *fp = fopen(argv[i], "r");
     
     if (fp == NULL) {
     printf("wgrep: cannot open file\n");
     exit(1);
   }
   
   
   else{ //NOT NULL CASE
   while(fgets(bound, sizeof(bound), fp) != NULL) {
        if (strstr(bound, argv[1])) { /*ARGC IS HERE */
            printf("%s",bound);
    }   
   }
  }
  fclose(fp);
 }

exit(0);
}
 
 
 
