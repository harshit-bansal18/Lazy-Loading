#include "build/liblazy.h"
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10
int main() {
    printf("Starting C program...\n");
    int* data_addr = (int*)(malloc(SIZE*sizeof(int)));
    int* lock_addr = (int*)(malloc(sizeof(int)));
    *lock_addr = 1;
    run(data_addr, lock_addr, SIZE);
    free(data_addr);
    free(lock_addr);
    printf("code complete.\n");   
}