#!/bin/sh

./configure \
LDFLAGS="-Xlinker --rpath=/usr/local/cs/gcc-$(gcc -dumpversion)/lib"

make clean
gcc -S -O2 -fno-inline -fstack-protector-strong -I .. -I . thttpd.c -o thttpd-sp.s

make clean
gcc -S -O2 -fno-inline -static-libasan -fsanitize=address -I .. -I . thttpd.c -o thttpd-as.s

make clean
gcc -S -O2 -fno-inline -fno-stack-protector -zexecstack -I .. -I . thttpd.c -o thttpd-no.s
