/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:24:13 by aghazi            #+#    #+#             */
/*   Updated: 2022/03/14 15:16:46 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *a = "Abdullah";
    // char a = 'S';
    int i;
    int j = 0;
    int k = 0;
    int at = atoi(argv[1]);
    while (a[k])
    {
        i = 7;
        while (i >= 0)
        {
            j = a[k] >> i & 1;
            // printf("%d",j);
            if (j)
                kill(at,SIGUSR2);
            else
                kill(at,SIGUSR1);
            --i;
            usleep(2000);
        }
        k++;
        printf("\n");
    }
        // i = 7;
        // while (i >= 0)
        // {
        //     j = a >> i & 1;
        //     // printf("%d",j);
        //     if (j)
        //         kill(at,SIGUSR2);
        //     else
        //         kill(at,SIGUSR1);
        //     --i;
        //     usleep(2000);
        // }
        printf("\n");
    // printf("\n");
	return (0);
}
