#!/bin/sh

gcc -c bowling.c && \
    g++ -I./libs/include libs/lib/libgtest.a bowling.o bowling_test.cc -o bowling_test && \
    ./bowling_test && \
    rm bowling_test
