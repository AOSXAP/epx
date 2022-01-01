#include <iostream>
#include <cstring>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <string>

#include "methods.h"
#include "exec.h"
#include "colors.h"
#include "functions.h"

//signal(SIGINT, funcs::signal_handler);

int main(int argc, char *argv[])
{
    system("clear");
    char *user_name = methods::user(), *shellx, *t;

    shellx = methods::init_usr(user_name ,  exec::deprecated_exec(
        "cat /proc/sys/kernel/hostname"
    ));

    std::cout<<shellx;

    while(t = methods::read_line()){
        char cpy[150];
        std::cout<<shellx;
        pid_t c_pid = fork();

        if (c_pid == -1) {
            std::cout<<"fork";
            perror("fork");
        } 
        else if (c_pid > 0){
            wait(nullptr);
        }
        else {
            try{
                strcpy(cpy , t); 
                throw(exec::fork_exec(t)); 
            }
            catch(int code){
                char *p = strtok(t , " ");

                if(strcmp(p , "cd") == 0){
                    funcs::cd(p);
                    break;
                }else if(strcmp(p , "path") == 0){
                    char *strx = funcs::path();
                    Color::CPRINT("green", strx);
                    break;
                }
                
                Color::CPRINT("red", "err: command not found");
            }

            exit(EXIT_SUCCESS);
        }
    }
}