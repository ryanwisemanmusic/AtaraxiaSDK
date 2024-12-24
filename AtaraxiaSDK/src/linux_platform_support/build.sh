#!/bin/bash

export QMake=/usr/local/wt5/bin/qmake 
export MAKE=make 

echo "Building project..."

# Linux generated Makefile
$QMAKE

# Linux's command to run the project
$MAKE

# Log to illustrate that your build is working
echo "Build process completed!"