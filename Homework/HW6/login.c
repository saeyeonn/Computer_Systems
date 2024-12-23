#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

void printflag()
{
    printf("This is secret code for you : CS13245768\n");
}

void func()
{
    char buffer[0x10];
    
    printf("Key : ");
    fflush(stdout);
    read(0, buffer, 0x20); // limit
    
    if (strncmp(buffer, "weakpass", 10)==0) 
    {
        printf("Login Successful!\n"); 
    }
    else 
    {
        printf("Login FAILED!!\n"); 
    }
}

int main(int argc, char* argv[])
{ 
    setvbuf(stdout, 0, _IOLBF, 0); 
    setvbuf(stdin, 0, _IOLBF, 0); 
    func();
    
    return 0; 
}