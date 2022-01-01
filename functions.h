#pragma once

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

namespace funcs{
    char* path();
    
    void cd(char* xarg){
        std::cout<<path()<<"\n";
        chdir(xarg);
        std::cout<<path()<<"\n";
    }

    char* path(){
        char *s = (char *) malloc(150 * sizeof(char)); 
        getcwd(s,150); return s;
    }

    void signal_handler(int num_code){

        std::cout<<num_code;
        std::cout<<"You can stop shell with :q";
    }
}
