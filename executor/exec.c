#include <stdio.h>

void execute(void* data_addr, void* lock_addr, int size) {

	int iter = 0;
	int* la = (int*)(lock_addr);
    int* da = (int*)(data_addr);
    printf("execute: addr of lock: %p\n", la);
	while(iter < 4) {
        if(*la == 2) {
            // consume the data
            for(int i =0; i < size; i++){
                printf("execute: in iteration %d : %d\n", iter, *(da + i));
            }
            printf("\n");
            (*(la)) = 1; // set to one
            iter++;
        }

	}
    *la = -1;
    return;
}