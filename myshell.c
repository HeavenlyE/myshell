#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>


//removes the last char from the end of a string
//mainly used to remove '\n' from the end of the last token
void removeLastChar(char *token){
    token[strlen(token) - 1] = '\0';
}

//used for "start" and "run" commands
void startProcess(char **token, int *pid){
    *pid = fork();
    if (*pid < 0){
        printf("myshell: error starting program: %s\n",token[0]);
        exit(1);
    }
    if(*pid == 0){
        // printf("Child process: ");
        // printf("running %s\n", token[0]);
        execvp(token[0], token);
        //execvp("ls",token);
        exit(0);
    }

}


int main(){

    char prompt[] = "myshell> ";
    char input[4096];
    char *token[99];
    char *command;
    char separator[] = " \t";
    int i;
    int pid = 0;
    int exitStat = 0;
    int errCheck;

    while(0 == 0){

        //prints the prompt and reads user input
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        command = strtok(input, separator);
        token[0] = strtok(NULL, separator);
        int j = 0;

        //separate the rest of the arguments
        while(token[j] != NULL && j<99){
            j++;
            token[j] = strtok(NULL, separator);
        }

        //remove the newline from the end of the last token
        if(token[0] == NULL){
            removeLastChar(command);
        }else{
            removeLastChar(token[j-1]);
        }

        // Print out the tokens
        //printf("Command: %s\n", command);
        // printf("Tokens: ");
        // for(i = 0; i < j; i++){
        //     printf("%s ", token[i]);
        // }
        // printf("\n");

        //running the different commands
        if(strcmp(command, "quit") == 0 || strcmp(command, "exit") == 0){
            exit(0);
        }
        else if(strcmp(command, "start") == 0){
            startProcess(token, &pid);
        }
        else if(strcmp(command, "run") == 0){
            startProcess(token, &pid);

            errCheck = waitpid(pid,&exitStat,0);
            if(errCheck < 0){
                printf("myshell: error: %s\n",strerror(errno));
            }

        }
        else if(strcmp(command, "wait") == 0){
            errCheck = wait(&exitStat);
            if(errCheck < 0){
                printf("myshell: error: %s\n",strerror(errno));
            }
        }
        else if(strcmp(command, "kill") == 0){

        }
        else if(strcmp(command, "stop") == 0){
            
        }
        else if(strcmp(command, "continue") == 0){
            
        }
        else if(strcmp(command, "") == 0){

        }
        else{
            printf("myshell: unkown command: %s\n", command);
        }
        // if(strcmp(command, "test") == 0){
        //     printf("Test:\n");
        //     execvp(token[0], token);
        // }
    };

}