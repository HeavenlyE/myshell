#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


void removeLastChar(char *token){
    token[strlen(token) - 1] = '\0';
}

void startProcess(char **token, int *pid){
    *pid = fork();
    if (*pid < 0){
        //err
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
    //char input[4];
    char input[4096];
    char *token[99];
    char *command;
    char separator[] = " \t";
    int i;
    int *pid;
    *pid = 0;
    int *exitStat;

    while(0 == 0){
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        command = strtok(input, separator);
        token[0] = strtok(NULL, separator);
        //printf("%s\n", token[0]);
        int j = 0;

        //separate the different arguments
        while(token[j] != NULL){
            j++;
            token[j] = strtok(NULL, separator);
            //printf("token[%d] %s\n", j, token[j]);
        }

        //remove the newline from the end of the last token
        if(token[0] == NULL){
            removeLastChar(command);
        }else{
            removeLastChar(token[j-1]);
        }
        //printf("%s this should be on same line\n",token[j-1]);

        // Print out the tokens
        //printf("Command: %s\n", command);
        // printf("Tokens: ");
        // for(i = 0; i < j; i++){
        //     printf("%s ", token[i]);
        // }
        // printf("\n");


        if(strcmp(command, "quit") == 0 || strcmp(command, "exit") == 0){
            exit(0);
        }
        else if(strcmp(command, "start") == 0){
            startProcess(token, pid);
        }
        else if(strcmp(command, "run") == 0){
            startProcess(token, pid);
            // printf("Waiting for %d...\n",*pid);
            waitpid(*pid,exitStat,0);
            printf("Done waiting...\n");
        }
        else if(strcmp(command, "wait") == 0){
            wait(exitStat);
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