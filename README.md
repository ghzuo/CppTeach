# CppTeach

Source codes and tools for C/C++ teaching. 

## Contents

1. src: example source codes for teaching
2. serv: web server for display data for projects
3. Dockerfile: docker image builder for develop environment and web server.

## Docker Usages

1. Install docker in computer: [Docker Tutorial](https://www.runoob.com/docker/docker-tutorial.html)
2. Build/download docker image: `docker build -t="yourname/cpplearn" .` or `docker pull ghzuo/cppteach`
3. Start new container from image: `docker run --name cpplearn -it -v $PWD/src:/root/src -p 8080:80 yourname/cpplearn`
4. Start an existed container: `docker start -i cpplearn`
5. Exit and stop container: `exit` in docker terminal
6. Exit container without stop: `Ctrl-P-Q`
7. Attach a running container: `docker attach cpplearn`
8. Brown webserver by url "localhost:8080"

## Todo

1. Revise the display server by Cling-jupyter
2. Including the source code into jupyter notebook
