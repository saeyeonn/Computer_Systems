#include <stdlib.h> 
#define NUM_FORKS 4 

char array[NUM_FORKS+2];

int pos = 0;

void work(void* id) {
    char writeMe = '0' + *(int*)id; 
    array[pos++] = writeMe;
}

int main() {
    char three = '3'; 
    int i;
    int pid[NUM_FORKS];

    for (i = 0; i < NUM_FORKS; i++) 
    { 
        if (!(pid[i] = fork())) 
        {
            work((void*)(&i));
            exit(0); 
        }
        waitpid(pid[i], NULL, 0); }
        array[pos++] = three; 
        array[pos] = '\0'; 
        printf("%s", array); 
        exit(0);
}


