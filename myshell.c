#include<stdio.h>
#include<string.h>


int main(){

    char prompt[] = "myshell> ";
    char input[4096];
    char *token[100];
    char separator[] = " ";
    int i = 0;

    while(1 == 1){
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        token[0] = strtok(input, separator);
        printf("%s\n", token[0]);
        int j = 0;

        
        while(token[j] != NULL){
            j++;
            token[j] = strtok(NULL, separator);
            printf("token[%d] %s\n", j, token[j]);
        }

        if(strcmp(token[0], "quit") == 0 || strcmp(token[0], "exit")){
            exit(0);
        }
    };

}