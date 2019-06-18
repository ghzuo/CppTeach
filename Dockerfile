FROM ubuntu
LABEL Version=0.1 \
  MAINTAINER="Guanghong Zuo<ghzuo@fudan.edu.cn"\
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
RUN apt-get install -yqq libboost-all-dev
RUN apt-get install -yqq libgsl-dev

## for web server
RUN apt-get install -yqq apache2 php
RUN /bin/rm -f /var/www/html/*
ADD serv/web/* /var/www/html/
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf
EXPOSE 80

## other Tools
RUN apt-get install -yqq ssh
RUN apt-get install -yqq lftp
RUN apt-get install -yqq nmap

## clean apt-get
RUN apt-get clean

## for workplace
COPY serv/docker/autorun.sh /etc/init.d/autorun.sh
WORKDIR /root
CMD [ "/etc/init.d/autorun.sh" ]