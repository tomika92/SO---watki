#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
printf("PID = %d\n", getpid());
printf("PPID = %d\n", getppid());
printf("UID = %d\n", getuid());
printf("GID = %d\n", getgid());
}
