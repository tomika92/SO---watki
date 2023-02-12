
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void identyfikatory()
{
        printf("PID = %d, ", getpid());
        printf("PPID = %d, ", getppid());
        printf("UID = %d, ", getuid());
        printf("GID = %d\n", getgid());
}

int main()
{
        int i;
        pid_t pierwszy=getpid();
        char command[25];
        identyfikatory();
        for(i=0;i<3;i++)
        {
                switch(fork())
                {
                        case -1:
                                perror("Blad funkcji fork");
                                exit(1);
                        case 0:
                                identyfikatory();
                                break;
                }
        }
        if(pierwszy!=getpid())
        {
                sleep(10);
        }
        else
        {
                sprintf(command, "pstree -p %d", pierwszy);
                system(command);
        }
        return 0;
}
