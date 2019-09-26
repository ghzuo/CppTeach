FROM ubuntu
LABEL Version=0.1 \
  MAINTAINER="Guanghong Zuo<ghzuo@fudan.edu.cn>"\
  description="Docker image for C/C++ teaching Server" 

## for timezone
ENV DEBIAN_FRONTEND noninteractive
RUN echo "Asia/Shanghai" > /etc/timezone 
RUN apt-get update -y && apt-get install -yqq tzdata 
RUN rm /etc/localtime && ln -fs /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
RUN dpkg-reconfigure -f noninteractive tzdata

## for web server
RUN apt-get install -yqq apache2 php
RUN /bin/rm -f /var/www/html/*
ADD web/* /var/www/html/
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf
EXPOSE 80

## clean apt-get
RUN apt-get clean

## for workplace
COPY autorun.sh /etc/init.d/autorun.sh
WORKDIR /root
CMD [ "/etc/init.d/autorun.sh" ]