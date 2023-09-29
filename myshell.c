#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int removeLastChar(char *token){
    token[strlen(token) - 1] = '\0';
}

int main(){

    char prompt[] = "myshell> ";
    //char input[4];
    char input[4096];
    char *token[100];
    char separator[] = " ";
    int i;

    while(0 == 0){
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        token[0] = strtok(input, separator);
        //printf("%s\n", token[0]);
        int j = 0;

        //separate the different arguments
        while(token[j] != NULL){
            j++;
            token[j] = strtok(NULL, separator);
            //printf("token[%d] %s\n", j, token[j]);
        }

        //remove the newline from the end of the last token
        removeLastChar(token[j-1]);
        //printf("%s this should be on same line\n",token[j-1]);

        for(i = 0; i < j; i++){
            printf("%s ", token[i]);
        }
        printf("\n");


        if(strcmp(token[0], "quit") == 0 || strcmp(token[0], "exit") == 0){
            exit(0);
        }
    };

}