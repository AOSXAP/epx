#pragma once

#include <iostream>
#include <unistd.h>

int main(){
    char s[100];
    std::cout<<getcwd(s,100)<<"\n";
    chdir("../");
    chdir("files");
    std::cout<<getcwd(s,100);;
}

namespace funcs{
    void cd(char *xarg){
        chdir(xarg);
    }

    char* path(){
        char s[100]; return getcwd(s,100);
    }
}