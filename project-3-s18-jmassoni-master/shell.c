#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {

    char t[64];
    char *token;
    char *args[16]; // array of arg strings //
    int i = 0;

    while(1){
        
        printf("Please enter your command human >");
        
        // fgets to read command from terminal //
        fgets(t, 64, stdin);
        token = strtok(t, " \n\t");
        
        while(token) {
            
            args[i] = token;
            i++;
            token = strtok(NULL, " \n\t");
            
            //printf("%s", t);
            // Put the token string into the next free spot in the args array //

        }
        
        // args[i] = NULL;
        // args[0] is the main command //
        
        if(strcmp(args[0], "pwd") == 0){
            
            char cwd[1024];
            printf("test");
            if (getcwd(cwd, sizeof(cwd)) != NULL){
                printf("%s\n", cwd);
            } else {
                perror("Silly Human Error");
            }

        } else if (strcmp(args[0], "exit") == 0){
            
            exit(0);
            
        } else if (strcmp(args[0], "cd")){
            
            char *directory = args[1];
            int ret;


            ret = chdir (directory);

            
        } else {
            
            
        }
        
        
        
        //else if (args[0] == "cd"){
            
        //     // Directory to change to should be args[1]
            
        //     //chdir(args[1]);  // Check syntax for chdir
        //     int direc = fork(); // don't need fork for cd
        //     if(direc == 0){
                
        //         chdir(args[1]);
                
        //     }
            
        //     else if(direc > 0){
                
        //         int direc = wait(NULL);
        //     }

        // } else {
        // // General else case
        
        // // Set up the arguments for execvp
        // // The name of the command: args[0]
        // // The rest of the args array
        // // The last element in the args array has to be NULL
        
        
        //     // int rc = fork();
            
        //     // if (rc == 0) {
                
        //     //     // sets up args and then calls execvp
                
        //     // } else if (rc > 0) {
                
        //     //     // parent waits 
        //     // }
            
            
        
        // // Need parent case and child case
        // // Use rc from fork
        
        // // Parent calls wait
        // // child calls execvp
        
        // //     execvp( token, arg );
        // }
        
        
        
    }
    
    
   
    
    // look through args array for > symbol
    // look at index after > symbol for file name
    // open that file name
    // overwrite the > character with a NULL
    
    return 0;
    
}

