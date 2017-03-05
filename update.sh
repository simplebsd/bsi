#!/bin/sh

/usr/local/bin/git pull origin master
clang++ bsi.cpp -o /usr/local/bin/bsi
