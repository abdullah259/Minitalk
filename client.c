/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:24:13 by aghazi            #+#    #+#             */
/*   Updated: 2022/03/21 18:01:17 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

#include "minitalk.h"

int     main(int argc, char **argv)
{
    int i;
    int j;
    int k;
    int at;

    j = 0;
    k = 0;
    at = ft_atoi(argv[1]);
    if (argc == 3)
    {
        if (at >= 100 && at <= 1000000)
        {
            while (argv[2][k])
            {
                i = 7;
                while (i >= 0)
                {
                    j = argv[2][k] >> i & 1;
                    if (j)
                        kill(at,SIGUSR2);
                    else
                        kill(at,SIGUSR1);
                    --i;
                    usleep(100);
                }
                k++;
            }
        }
        else
            write(1,"Wrong argement you have to input first name of client then PID also the string",79); 
    }
    return (0);
}
