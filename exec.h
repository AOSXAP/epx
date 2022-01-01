#pragma once

#include <iostream>
#include <cstring>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>

namespace exec{
    char* deprecated_exec(char command[]){
        FILE* tf; char output[1024] , *t;

        tf = popen(command , "r");

        if(tf != NULL){
            fgets(output , 1024 , tf);
            output[strlen(output) - 1] = '\0';
        }else return "err";

        fclose(tf); 

        strcpy(t, output); 
        return t;
    }

    void form_arr(char arr[][1000], char *args, int &i){
        char *p = strtok(args , " ");

        while(p){
            strcpy(arr[i++] , p);
            p = strtok(NULL , " ");
        }
    }

    void prepare_arr(char *parr[], char arg_arr[][1000], int i, int j){
        for(j = 0; j < i; j++){
            *(parr + j) = arg_arr[j];
        }

        parr[++j] = NULL;

        for(int i = 0 ; i < j ; i++){
            std::cout<<parr[j]<<" ";
        }
    }

    int fork_exec(char* args){
        int i = 0, j; char arg_arr[1000][1000];
        form_arr(arg_arr , args, i);

        char* command_name = arg_arr[0], *parr[1000];
        prepare_arr(parr, arg_arr, i, j);
        
        return execvp(command_name, parr);
    }
}