#include <iostream>
#include <cstring>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

#include "methods.h"


int main(int argc, char *argv[])
{
    char *user_name = methods::user(), *t;

    t = methods::init_usr(user_name ,  methods::native_exec(
        "cat /proc/sys/kernel/hostname"
    ));

    std::cout<<t;

    /*
    while(t = methods::read_line()){
        char t_arr[1024]; std::cout<<usr;
        std::cout<<"\n"<<methods::native_exec(t)<<"\n";
    }
    */
}