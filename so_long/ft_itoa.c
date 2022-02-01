/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:23:08 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/12 13:33:05 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

static char	*ft_check_str(int i, long temp, char *str, int n)
{
	if (temp < 0)
		temp = temp * (-1);
	while (temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (--i >= 0 && n != 0)
	{
		if (n >= 0)
			str[i] = 1 * (n % 10) + '0';
		else
			str[i] = -1 * (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	long	temp;
	char	*str;

	i = 1;
	str = NULL;
	if (n < 0)
		i++;
	temp = n;
	return (ft_check_str(i, temp, str, n));
}
