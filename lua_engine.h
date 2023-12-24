#pragma once
#include "external/sol/sol.hpp"
#include "server.h"
#include <string>

sol::state lua_engine;


void set_pattern_content(std::string pattern,std::string content,std::string type){
    server.Get(pattern, [content,type](const httplib::Request &, httplib::Response &response) {
        response.set_content(content, type);
    });
}

void stop_on_pattern(std::string pattern){
    server.Get(pattern, [&](const httplib::Request &, httplib::Response &response) {
        server.stop();
    });
}


void init_lua_engine(){

    lua_engine.open_libraries(sol::lib::base);


    lua_engine.set_function("server_listen",[](std::string host, int port){server.listen(host,port);});


    lua_engine.set_function("set_pattern_content",[](std::string pattern,std::string content,std::string type){set_pattern_content(pattern,content,type);});
    lua_engine.set_function("stop_on_pattern",[](std::string pattern){stop_on_pattern(pattern);});


    lua_engine.set_function("server_add_mount",[](std::string point,std::string directory){server.set_mount_point(point,directory);});

}