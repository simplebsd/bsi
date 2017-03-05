#!/bin/sh

/usr/local/bin/git pull master origin
clang++ bsi.cpp -o /usr/local/bin/bsi
