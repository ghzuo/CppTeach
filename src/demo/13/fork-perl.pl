#!/usr/bin/perl -w
use strict;
use warnings;
my $COMMDIR;
BEGIN{($COMMDIR = $0) =~ s/[^\/]+$//;}
###
# Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai, China.
# See the accompanying Manual for the contributors and the way to cite this work.
# Comments and suggestions welcome. Please contact
# Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>
# 
# @Author: Dr. Guanghong Zuo
# @Date: 2018-12-24 13:39:37
# @Last Modified By: Dr. Guanghong Zuo
# @Last Modified Time: 2018-12-24 13:39:37
###

my $PSNUM = 4;
my $j;

foreach $item(@list){
  if(fork()){
    wait if ++$j >= $PSNUM;  #IMPORTANT
  } else {
    close(STDIN);
    open(STDIN, "/dev/null");
    system("command");
    exit;  # VERY IMPORTANT
  }
}