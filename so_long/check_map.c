/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:39:49 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 14:31:15 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

int	is_w_e(char c, t_file *file, int i, int j)
{
	if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'E')
	{
		(file->exit_d)++;
		return (0);
	}
	else if (c == 'P')
	{
		(file->player)++;
		if (file->player != 1)
			return (1);
		file->x = j;
		file->y = i;
		return (0);
	}
	else if (c == 'C')
	{
		(file->colects)++;
		return (0);
	}
	return (1);
}

void	v_map_e(t_file *file, char **map)
{
	if (file->colects < 1)
		free_map(map, file->line_count, "error :no colection in the map");
	else if (file->player == 0)
		free_map(map, file->line_count, "error : no player in the map");
	else if (file->exit_d < 1)
		free_map(map, file->line_count, "error : no exit in the map");
}

void	ft_check_map(char **map, t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && file && map && i < file->line_count)
	{
		j = 0;
		while (map[i][j] && j < file->line_len - 1)
		{
			if ((i == 0 || i == file->line_count - 1) && map[i][j] != '1')
				free_map(map, i, "error : map not closed");
			if ((j == 0 || j == file->line_len - 1) && map[i][j] != '1')
				free_map(map, i, "error : map not closed");
			else if (is_w_e(map[i][j], file, i, j))
				free_map(map, i, "error : wrong element in the map");
			j++;
		}
		i++;
	}
	v_map_e(file, map);
}
