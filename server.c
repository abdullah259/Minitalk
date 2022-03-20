// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

#include "minitalk.h"

void	hansdleus1(int sig)
{
    static int i;
    static char J;

    if (sig == SIGUSR2)
    {
        printf("1");
        J |= 1;
    }
    i++;
    if (i == 8)
    {
        write(1,&J,1);
        i = 0;
        J = 0;
    }
    J = J << 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
    char *printPid;
    int i;

    i = 0;
    printPid = ft_itoa(pid);
    while (printPid[i])
    {
        write(1,&printPid[i],1);
        i++;
    }
    
	// printf("PID: %d\n", pid);
	signal(SIGUSR1, &hansdleus1);
	signal(SIGUSR2, &hansdleus1);
    while (1)
    {
        pause();
    }
    
	return (0);
}