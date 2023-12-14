# Custom Memory Allocator

## Compilation

Compile the memory allocator using the following command:

```bash
gcc -o memalloc.so -fPIC -shared -Wno-deprecated-declarations memalloc.c
```

## Usage
 
Assuming you are using a Unix-type operating system, follow these steps to use the custom memory allocator when running commands:

```bash
export LD_PRELOAD=$PWD/memalloc.so
```

This sets the `LD_PRELOAD` environment variable to the path of the compiled `memalloc.so` shared library.

## Stop Using the Memory Allocator

To stop using the custom memory allocator, simply run:

```bash
unset LD_PRELOAD
```

This unsets the `LD_PRELOAD` environment variable, reverting to the default memory allocation behavior.
