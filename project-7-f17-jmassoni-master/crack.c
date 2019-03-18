#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <crypt.h>

int test(char *hash, char *outputFileName, int cFlagSet, int lFlagSet,int nFlagSet) {
    
  FILE *output = fopen (outputFileName, "a");
  if(output == NULL){
    
    perror("fopen");
    return 1;
      
  }
    
    
  FILE *f = fopen("./words", "r");
  if (f == NULL){
    
    perror("fopen");
    return 1;
    
  }
    
  char buffer2[128];
    
  while (fgets(buffer2, sizeof(buffer2), f)) {
      
    buffer2[strlen(buffer2) - 1] = '\0';
      
    if(cFlagSet){
        
      buffer2[0] = buffer2[0]^' ';
        
    }
    
    if(lFlagSet){
        
      int i;
        
      for(i = 0; i < strlen(buffer2); i++){
          
        if (buffer2[i] == 'a'){
          
          buffer2[i] = '@';
            
        }
        
        if (buffer2[i] == 'e'){
          
          buffer2[i] = '3';
            
        }
          
        if (buffer2[i] == 'i'){
          
          buffer2[i] = '!';
          
        }
          
        if (buffer2[i] == 'l'){
          
          buffer2[i] = '1';
            
        }
          
        if (buffer2[i] == 'o'){
          
          buffer2[i] = '0';
          
        }
          
        if (buffer2[i] == 's'){
          
          buffer2[i] = '5';
        
        }
        
      }
      
    }  
      
    if (!nFlagSet) {
        
      char *buffer_pointer = buffer2;
      char *book = crypt(buffer_pointer, "$1$");
        
      if(strcmp (book, hash) == 0){
          
        printf("%s\n", buffer2);
        fprintf(output, "%s\n", buffer2);
            
      } 
      
      } else {
          
          int i;
          int len = strlen(buffer2);
            
          for (i = 0; i < 10; i++) {
              
            buffer2[len] = '0' + i;
            char *buffer_pointer2 = buffer2;
            char *finally = crypt(buffer_pointer2, "$1$");
            
            if(strcmp (finally, hash) == 0){
          
              printf("%s\n", buffer2);
              fprintf(output, "%s\n", buffer2);
            
            }
              
          }
          
      }
    
  }
      
  fclose(f);
  fclose(output);
    
  return 0;
  
}
  

int main(int argc, char *argv[]){

  char c;
  int nFlagSet = 0;
  int cFlagSet = 0;
  int lFlagSet = 0;
  char *iValue = NULL;
  char *oValue = NULL;
  char *dValue = NULL;

  while(( c = getopt (argc, argv, "i:o:d:ncl")) != -1){
    
    switch (c){
     
      case 'i':
        iValue = optarg;
        break;
      
      case 'o':
        oValue = optarg;
        break;
        
      case 'd':
        dValue = optarg;
        break;
      
      case 'n':
        nFlagSet = 1;
        break;
        
      case 'c':
        cFlagSet = 1;
        break;
      
      case 'l':
        lFlagSet = 1;
        break;
        
    }
    
    if(iValue != NULL){
      
      printf("-i flag present argument = %s\n", iValue);
      
    }
    
    if(oValue != NULL){
      
      printf("-o flag present argument = %s\n", oValue);
      
    }
    
    if(dValue != NULL){
      
      printf("-d flag present argument = %s\n", dValue);
      
    }
    
    if(nFlagSet){
      
      printf("-n flag present.\n");
      
    }
    
    if(cFlagSet){
      
      printf("-c flag present.\n");
      
    }
    
    if(lFlagSet){
      
      printf("-l flag present.\n");
      
    }
    
  }


  FILE *f = fopen(iValue, "r");
  if (f == NULL){
        
    perror("fopen");
    return 1; 
        
  }
    
    
  char buffer[128];
    
  while (fgets(buffer, sizeof(buffer), f)) {

    strtok(buffer, ":");

    char *hash = strtok(NULL, ":");

    if (hash[strlen(hash) - 1] == '\n') {
      hash[strlen(hash) - 1] = '\0';
    } 
    
    printf("%s\n", hash);
    test(hash, oValue  , cFlagSet, lFlagSet, nFlagSet);
  }

  return 0;
  
}