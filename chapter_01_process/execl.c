#include <unistd.h>
#include <stdio.h>

int main()
{
    if (execl("/bin/ls", "ls", "-al", NULL) == -1) {
        perror("excel");
    }
    printf("+ after excel\n");
    return 0;
}