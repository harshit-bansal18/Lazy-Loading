#include <stdio.h>
#include <unistd.h>


volatile int val;

void execute(void* data_addr, void* lock_addr, int size) {

	int iter = 0;
	int* la = (int*)(lock_addr);
    int* da = (int*)(data_addr);
    
    printf("execute: addr of lock: %p\n", la);
    val = *la;
	while(iter < 4) {
        // printf("consumer.\n");
        val = *la;
        if(val == 2) {
            // consume the data
            for(int i =0; i < size; i++){
                printf("execute: in iteration %d : %d\n", iter, *(da + i));
            }
            printf("\n");
            iter++;
            (*(la)) = 1; // set to one
        }
        // sleep(1);

	}
    
    printf("execute: outside the loop\n");
    *la = -1;
    return;
}