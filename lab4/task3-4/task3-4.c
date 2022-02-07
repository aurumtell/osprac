#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char *envp[]) {
    int pid = fork();
    if (pid == -1) {
        printf("New process error\n");
    }
    else if (pid == 0) {
        printf ("Is a child. Child PID - %d.\n", getpid());
        (void) execle("/bin/cat", "/bin/cat", argv[1], 0, envp);
        printf("Exec error");
        exit(-1);
    } else {
        printf ("Is a parent. Parent PID - %d, while child PID - %d.\n", getpid(), pid);
    }
    return 0;
}