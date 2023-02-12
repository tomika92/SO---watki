#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
        int i, kod, ex, status, mPID;
        mPID=getpid();
        printf("Proces macierzysty posiada PID o nr %d\n", mPID);
        for(i=1;i<=3;i++)
        {
                switch(fork())
                {
                        case -1:
                                perror("Blad funkcji fork");
                                exit(1);
                        case 0:
                                printf("Proces potomny %d\n", i);
                                ex=execl("./program1_1.out","program1_1.out",NULL);
                                if(ex==-1)
                                {
                                        perror("Blad funkcji execl");
                                        exit(1);
                                }
                                break;
                        default:
                                //Proces macierzysty
                                sleep(1);
                }
        }

        for(i=1;i<=3;i++)
        {
                kod=wait(&status);
                if(kod==-1)
                {
                        perror("Blad funkcji wait");
                        exit(1);
                }
                printf("Kod powrotu procesu potomnego %d o PIDdzie %d jest rowny %d\n", i, kod, status);
        }

        return 0;
}
