#include<stdio.h> 
#include<signal.h> 
  
// Handler for SIGINT, caused by 
// Ctrl-C at keyboard 
void interrupt(int signal) 
{ 
    printf("There was an interrupt %d\n", signal);
    exit(1);
} 
  
int main() 
{ 
    signal(SIGINT, interrupt); 
    while (1) ; 
    return 0; 
} 