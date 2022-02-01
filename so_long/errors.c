/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:39:25 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 14:25:42 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	ft_putstr(char *err)
{
	while (*err)
	{
		write(1, err, 1);
		err++;
	}
}

void	error_1(void)
{
	perror("error\n");
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int line, char *error)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putstr(error);
	exit(EXIT_FAILURE);
}
