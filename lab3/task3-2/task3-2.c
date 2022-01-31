#include <stdio.h>
#include <unistd.h>

int main (){
    pid_t pid = fork ();

    if (pid == -1) {
        printf("Something went wrong.");
    } else if (pid == 0){
        printf ("Is a child. Child PID - %d.\n", getpid());
    } else {
        printf ("Is a parent. Parent PID - %d, while child PID - %d.\n", getpid(), pid);
    }

    return 0;
}