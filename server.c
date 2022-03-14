#include <stdio.h>
#include <signal.h>
#include <unistd.h>
char letter;

void	hansdleus1(int sig)
{
    static int i = 0;
    static unsigned char J;

    if (sig == SIGUSR1 && i != 8)
    {
        J = J | (0 >> i);
        i++;
        printf("0");
    }
    else if (sig == SIGUSR2 && i != 8)
    {
        printf("1");
        J = J | (128 >> i);
        i++;
        // printf("1");
    }
    if (i == 8)
    {
        write(1,&J,1);
        i = 0;
        J = 0;
    }
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, &hansdleus1);
	signal(SIGUSR2, &hansdleus1);
	// printf("%c\n",letter);
    while (1)
    {
        ;
    }
    
	return (0);
}