#honey
portable and lightweight webserver written in c++

### what is honey?
honey is a multiplatform , lightweight and portable webserver that can be used to host files and websites,the webserver is configurable using lua file

### how to use it?
1. first you need generate project files using [premake5](https://premake.github.io/) build system , and then compile the project files
2. then create a `.lua` file and write the configurations for it , here is an detailed example :
```
set_pattern_content("/hi","hello world!","text/plain")
-- this function set the content of the pattern

server_listen("127.0.0.1",8080)
-- now lets start the server on localhost and port 8080
```
3. now start honey by this command :
```
honey <your_file.lua>
```
4. to make sure webserver works fine goto `localhost:8080/hi` and you should see the text `hello world!`
