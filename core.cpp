#include <iostream>
#include <cstring>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

#include "methods.h"
#include "exec.h"

int main(int argc, char *argv[])
{
    char *user_name = methods::user(), *shellx, *t;

    shellx = methods::init_usr(user_name ,  exec::deprecated_exec(
        "cat /proc/sys/kernel/hostname"
    ));

    std::cout<<shellx;

    while(t = methods::read_line()){
        std::cout<<shellx;
        pid_t c_pid = fork();

        if (c_pid == -1) {
            std::cout<<"fork";
            perror("fork");
        } 
        else if (c_pid > 0) wait(nullptr);
        else {
            exec::fork_exec(t); 
            exit(EXIT_SUCCESS);
        }
    }
}