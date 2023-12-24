#include "httplib.h"
#include "lua_engine.h"

int main(int argc, char *argv[]){

    init_lua_engine();

    if (argc > 1) {
        lua_engine.script_file(argv[1]);
    }

    

}