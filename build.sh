make
gcc -c main.c
gcc -o yo main.o -L. -lftprintf
./yo