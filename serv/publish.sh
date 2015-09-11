#!/bin/bash

local=${0%/*}'/web/'
remote='hao:/var/www/cpplearn'

rsync -av --exclude=".DS_Store" $local $remote 
