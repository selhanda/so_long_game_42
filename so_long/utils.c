/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:40:46 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 15:03:25 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((*p1 != '\0' && *p2 != '\0') && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

void	check_file(char *str)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".ber") != 0)
	{
		perror("extention error\n");
		exit(EXIT_FAILURE);
	}
}

void	init_file(t_file *file)
{
	file->line_count = 0;
	file->line_len = 0;
	file->player = 0;
	file->x = 0;
	file->y = 0;
	file->exit_d = 0;
	file->colects = 0;
}

char	**ft_malloc_map(int fd, t_file *file)
{
	char	**map;
	char	*line;

	if (fd < 0)
		error_1();
	line = get_next_line(fd);
	if (!line || line[0] == 0)
	{
		free(line);
		error_1();
	}
	while (line)
	{
		free(line);
		(file->line_count)++;
		line = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (file->line_count) + 1);
	if (!map)
		free_map(map, file->line_count, "error in map");
	return (map);
}

char	**ft_get_map(int fd, char **map, t_file *file)
{
	int	i;

	i = 0;
	map[0] = get_next_line(fd);
	if (!map[i])
	{
		free(map[i]);
		error_1();
	}
	file->line_len = ft_strlen(map[0]);
	i++;
	while (i < file->line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map(map, i, "error in map");
		if (ft_strlen(map[i - 1]) != file->line_len)
			free_map(map, i, "error :The map must be rectangular");
		i++;
	}
	i--;
	if (ft_strlen(map[i]) != file->line_len - 1)
		free_map(map, i, "error :The map must be rectangular");
	ft_check_map(map, file);
	return (map);
}
