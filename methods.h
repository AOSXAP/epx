#include <iostream>
#include <cstring>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

#define infinite 1

char def_usr[] = "shell> ";

char current[512];
struct termios term;

namespace methods{
    char* native_exec(const char command[]);
    
    void prep_string(char xd[]){
        strcpy(xd + strlen(xd) - 1 , xd + strlen(xd));
    }

    char* user(){
        char xd[512];
        FILE* t = popen("whoami" , "r");
            
        if(t == NULL || fgets(xd, 512, t) == NULL) return def_usr;
        else{
            prep_string(xd); strcpy(def_usr , xd);
        }

        fclose(t);    
        return def_usr;
    }
    
    void init_usr(char user_name[]){
        char full_user[1024];
        full_user[0] = '[';

        strcpy(full_user + 1 , user_name);

        strcat(full_user , "@");

        char *hostname = native_exec
            ("cat /proc/sys/kernel/hostname");

        strcat(full_user , " epx]> ");

        strcpy(user_name , full_user);

    }
    
    namespace echo{
        //disable terminal input
        void disable(){
            tcgetattr(fileno(stdin), &term);
            term.c_lflag &= ~ECHO;
            tcsetattr(fileno(stdin), 0, &term);
        }
        
        void enable(){
            term.c_lflag |= ECHO;
            tcsetattr(fileno(stdin), 0, &term);
        }
    }
    
    char* read_line(){
        int p = 0, buffer_size = 1024;
        char *buffer = (char *)malloc(sizeof(char) * buffer_size), c ;
        
        
        while(infinite){
           c = getchar();
           
           if(c == '\n') {
                   buffer[p] = '\0';
                   return buffer;
           }
           else{
               if(p >= buffer_size){
                   buffer_size += 1024;
                   buffer = (char *) realloc(buffer , buffer_size);
               }
                   buffer[p] = c; 
           }
           p++;
        }
    }  

    char* native_exec(const char command[]){
        FILE* tf; char output[1024] , *t;

        tf = popen(command , "r");

        if(tf != NULL){
            fgets(output , 1024 , tf);
            prep_string(output);
        }else return "err";

        fclose(tf); 

        strcpy(t, output); 
        return t;
    }
}
