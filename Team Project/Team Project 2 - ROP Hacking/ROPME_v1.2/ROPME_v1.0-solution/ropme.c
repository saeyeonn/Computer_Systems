#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void gift(){
        __asm__ volatile (
                "pop %rdx \n\t"
                "pop %rsi \n\t"
                "pop %rdi \n\t"
        );
}

void func(){
	char overflowme[32];
	read(0, overflowme, 0x200);	
}
int main(int argc, char* argv[]){
	setvbuf(stdout, 0, _IOLBF, 0); 
	setvbuf(stdin, 0, _IOLBF, 0); 
	func();
	write(1, "DONE\n", 5); 
	return 0;
}

