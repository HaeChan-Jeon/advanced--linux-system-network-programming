#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int i=0;
    pid_t ret;

    for (i = 0; i < 3; ++i) {
        ret = fork();
        printf("[%d] PID(%d) PPID(%d) %d\n", i, getpid(), getppid(), ret);
#ifndef OMIT_SWITCH
        switch (ret) {
        case 0:
            pause();
            break;
        case -1:
            break;
        default:
            break;
        }
#endif
    }
    wait(NULL);
    return 0;
}