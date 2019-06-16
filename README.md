# CppTeach

Source codes and tools for C/C++ teaching. 

## Contents

1. src: example source codes for teaching
2. serv: web server for display data for projects
3. Dockerfile: docker image builder for develop environment and web server.

## Docker Usages

1. Install docker in computer: [Docker Tutorial](https://www.runoob.com/docker/docker-tutorial.html)
2. build/download docker image: `docker build -t="YourName/CppLearn" .` or `docker pull ghzuo/cppteach`
3. run new container from image: `docker run --name CppLearn -i -t -p 8080:80 YourName/CppLearn`
4. exit container: `exit` in docker terminal
5. start an existed container: `docker start -i CppLearn`
6. start the webserver: `apachectl start` in docker terminal, and brown it by url "localhost:8080"

## Todo

1. Revise the display server by Cling-jupyter
2. Including the source code into jupyter notebook
