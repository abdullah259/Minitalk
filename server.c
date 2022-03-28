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
    int i;
    char *printPid;

	pid = getpid();
    i = 0;
    printPid = ft_itoa(pid);
    while (printPid[i])
    {
        write(1,&printPid[i],1);
        i++;
    }
	signal(SIGUSR1, &hansdleus1);
	signal(SIGUSR2, &hansdleus1);
    while (1)
        pause();
    
	return (0);
}