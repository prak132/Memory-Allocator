run
gcc -o memalloc.so -fPIC -shared -Wno-deprecated-declarations memalloc.c

then
export LD_PRELOAD=$PWD/memalloc.so

unset LD_PRELOAD