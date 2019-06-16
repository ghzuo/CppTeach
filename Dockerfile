FROM ubuntu
LABEL Version=0.1 \
  MAINTAINER="Guanghong Zuo<ghzuo@fudan.edu.cn"\
  description="Docker image for C/C++ teaching" 

  ## for time zone
ENV TZ Asia/Shanghai
ENV DEBIAN_FRONTEND noninteractive
RUN echo $TZ > /etc/timezone 
RUN apt-get update && apt-get install -y tzdata 
RUN rm /etc/localtime && ln -fs /usr/share/zoneinfo/$TZ /etc/localtime
RUN dpkg-reconfigure -f noninteractive tzdata

## for develop environment
RUN apt-get install -y build-essential 
RUN apt-get install -y cmake vim less
RUN apt-get install -y libeigen3-dev libarmadillo-dev libfftw3-dev
RUN apt-get install -y libboost-all-dev liblapack-dev libnetcdf-dev

## for web server
RUN apt-get install -y apache2 php nmap
RUN /bin/rm -f /var/www/html/*
ADD serv/web/* /var/www/html/
EXPOSE 80

## other Tools
RUN apt-get install -y ssh

## clean apt-get
RUN apt-get clean

## for workplace
VOLUME [ "/data" ]
WORKDIR /data
CMD [ "/bin/bash" ]