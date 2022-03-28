/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:15:40 by aghazi            #+#    #+#             */
/*   Updated: 2022/03/21 12:36:03 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "last-up-libft/libft.h"
#include "minitalk.h"

static int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int	i;
	int	k;

	k = n <= 0;
	i = n;
	while (i)
	{
		i /= 10;
		k++;
	}
	ptr = malloc(k * sizeof(char) + 1);
    if (!ptr)
        return (NULL);
	if (n == 0)
		ptr[0] = '0';
	ptr[k] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
	}
	while (n != 0)
	{
		ptr[--k] = absolute(n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
