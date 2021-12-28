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
    char *usr = methods::user(), *t;
    methods::init_usr(usr);
    std::cout<<usr;

    /*
    while(t = methods::read_line()){
        char t_arr[1024]; std::cout<<usr;
        std::cout<<"\n"<<methods::native_exec(t)<<"\n";
    }
    */
}