# CppTeach

Source codes and tools for C/C++ teaching. 

## Contents

1. src: example source codes for teaching
2. serv: web server for display data for projects
3. Dockerfile: docker image builder for develop environment and web server.

## Docker Usages

### For Development
1. Install docker in computer: [Docker Tutorial](https://www.runoob.com/docker/docker-tutorial.html)
2. Build/download docker image: `docker build -t="yourname/cpplearn" .` (in src) or `docker pull ghzuo/cppteach`
3. Start new container from image: `docker run --name cpplearn -it -v $PWD/demo:/root/demo yourname/cpplearn`
4. Start an existed container: `docker start -i cpplearn`
5. Exit and stop container: `exit` in docker terminal
6. Exit container without stop: `Ctrl-P-Q`
7. Attach a running container: `docker attach cpplearn`

### For Plot Server
1. Build/download docker image: `docker build -t="yourname/cppserv" .` (in serv) or `docker pull ghzuo/cppserv`
2. Start new container from image: `docker run --name cppserv -p 8080:80 yourname/cppserv &`
3. Start an existed container: `docker start cppserv`
4. Stop a running container: `docker stop cppserv`
5. Brown webserver by url "localhost:8080"
6. A better method for plot is jupyter-notebook

## Suggestion

1. Vscode + Docker + Remote Development: support manage docker and remote develop in Container/SSH

## Todo

1. Revise the display server by Cling-jupyter
2. Including the source code into jupyter notebook
