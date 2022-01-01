#pragma once

#include <ostream>
#include <iostream>
#include <unordered_map>
#include <sstream>

namespace Color 
{
    std::unordered_map<std::string, int> ColorMap
    ({
        {"red"     , 31},
        {"blue"    , 34},
        {"green"   , 32},
        {"original", 39}
    });

    std::string reset = "\033[0;39m\033[0m\n";

    void PREPSTREAMS
    (   
        std::stringstream &b,  int color_code , std::stringstream &s, 
            std::string msg, std::stringstream &e
    )
    {
        b << s.rdbuf() << color_code << "m" << msg;
            e << s.rdbuf()  << "m"; b << e.rdbuf();
    }

    void CPRINT(std::string color , std::string msg)
    {
        int color_code;

        std::unordered_map<std::string,int>::iterator itr = ColorMap.find(color);

        if(itr == ColorMap.end()) color_code = 39;
            else color_code = itr->second;

        std::stringstream ss("\033[0;") , begin , end; 
            PREPSTREAMS(begin , color_code , ss , msg , end);

        std::cerr << begin.rdbuf() << reset; 
    }

}
