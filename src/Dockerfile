FROM ubuntu
LABEL Version=0.1 \
  MAINTAINER="Guanghong Zuo<ghzuo@fudan.edu.cn>"\
  description="Docker image for C/C++ teaching" 

## for timezone
ENV DEBIAN_FRONTEND noninteractive
RUN echo "Asia/Shanghai" > /etc/timezone 
RUN apt-get update -y && apt-get install -yqq tzdata 
RUN rm /etc/localtime && ln -fs /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
RUN dpkg-reconfigure -f noninteractive tzdata

## for develop environment
RUN apt-get install -yqq build-essential
RUN apt-get install -yqq gdb valgrind gperf
RUN apt-get install -yqq cmake
RUN apt-get install -yqq git 
RUN apt-get install -yqq vim less
RUN apt-get install -yqq libeigen3-dev libarmadillo-dev 
RUN apt-get install -yqq libfftw3-dev liblapack-dev 
RUN apt-get install -yqq libnetcdf-dev

## other Tools
RUN apt-get install -yqq ssh

## clean apt-get
RUN apt-get clean

## for workplace
WORKDIR /root
