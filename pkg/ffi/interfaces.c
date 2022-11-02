#include "include/interfaces.h"
#include <stdio.h>
#include <unistd.h>

volatile int p;

int load_data(char* path, void* dataaddr, void* lockaddr, int size) {
    // load the data lazily into data_addr from the path
    // check for lock on every iteration
    int count = 1;
    printf("value of size: %d\n", size);
    int* data_addr = (int*)(dataaddr);
    int* lock_addr = (int*)(lockaddr);
    printf("value of lock: %d\n", *lock_addr);
    printf("load_data: addr of lock: %p\n", lock_addr);
    int iter = 4;
    p = *lock_addr;

    while(iter > 0) {
        // printf("loader.\n");
        p = *lock_addr;
        
        if(p == 1) {
            
            // load the data
            printf("load_data: loading data...\n");
            for(int i = 0; i < size; i++) {
                *(data_addr + i) = count*i;
            }
            iter--;
            count++;
            *lock_addr = 2; // indicate data loading is complete.
        }
        // sleep(1);
    }

    printf("load_data: outside the loop\n");
    return 1;
}