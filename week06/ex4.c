#include<stdio.h> 
#include<signal.h> 
  
// Handler for SIGINT, caused by 
// Ctrl-C at keyboard 
void interrupt(int signal) 
{ 
    printf("There was an interrupt %d\n", signal);
} 

void killed(int signal) 
{ 
    printf("You were killed %d\n", signal);
} 

void stop(int signal) 
{ 
    printf("You were stopped %d\n", signal);
}

void userFirst(int signal) 
{ 
    printf("first user's signal %d\n", signal);
}

int main() 
{ 
    signal(SIGINT, interrupt);
    signal(SIGKILL, killed);
    signal(SIGSTOP, stop);
    signal(SIGUSR1, userFirst); 
    while (1) ; 
    return 0; 
}
/*
Program prints 10 - signal of User defined signal 1
*/