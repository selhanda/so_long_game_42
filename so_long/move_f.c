/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:40:15 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 14:53:40 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

int	move_f(int keycode, t_swap *swap)
{
	if (keycode == 0x7C || keycode == 0x02)
	{
		if (!move_right(swap))
			putmap(swap->mlx, swap->map, swap->img, swap->file);
	}
	else if (keycode == 0x7B || keycode == 0x00)
	{
		if (!move_left(swap))
			putmap(swap->mlx, swap->map, swap->img, swap->file);
	}
	else if (keycode == 0x7D || keycode == 0x01)
	{
		if (!move_down(swap))
			putmap(swap->mlx, swap->map, swap->img, swap->file);
	}
	else if (keycode == 0x7E || keycode == 0x0D)
	{
		if (!move_up(swap))
			putmap(swap->mlx, swap->map, swap->img, swap->file);
	}
	else if (keycode == 0x35)
		close_win(&swap->mlx);
	mlx_string_put(swap->mlx.mlx,
		swap->mlx.win, 10, 20, L, ft_itoa(swap->moves));
	return (0);
}

int	move_right(t_swap *swap)
{
	mlx_clear_window (swap->mlx.mlx, swap->mlx.win);
	if (swap->map[swap->file.y][swap->file.x + 1] != '1' &&
			swap->map[swap->file.y][swap->file.x + 1] != 'E')
	{
		swap->file.x++;
		swap->moves++;
		printf("moves = %d\n", swap->moves);
	}
	if (swap->map[swap->file.y][swap->file.x] == 'C')
	{
		swap->map[swap->file.y][swap->file.x] = '0';
		swap->file.colects--;
	}
	if (swap->map[swap->file.y][swap->file.x + 1] == 'E')
	{
		if (swap->file.colects == 0)
		{
			game_over(swap);
			return (1);
		}
	}
	return (0);
}

int	move_left(t_swap *swap)
{
	mlx_clear_window (swap->mlx.mlx, swap->mlx.win);
	if (swap->map[swap->file.y][swap->file.x - 1] != '1' &&
			swap->map[swap->file.y][swap->file.x - 1] != 'E')
	{
		swap->file.x--;
		swap->moves++;
		printf("moves = %d\n", swap->moves);
	}
	if (swap->map[swap->file.y][swap->file.x] == 'C')
	{
		swap->map[swap->file.y][swap->file.x] = '0';
		swap->file.colects--;
	}
	if (swap->map[swap->file.y][swap->file.x - 1] == 'E')
	{
		if (swap->file.colects == 0)
		{
			game_over(swap);
			return (1);
		}
	}
	return (0);
}

int	move_down(t_swap *swap)
{
	mlx_clear_window (swap->mlx.mlx, swap->mlx.win);
	if (swap->map[swap->file.y + 1][swap->file.x] != '1' &&
			swap->map[swap->file.y + 1][swap->file.x] != 'E')
	{
		swap->file.y++;
		swap->moves++;
		printf("moves = %d\n", swap->moves);
	}
	if (swap->map[swap->file.y][swap->file.x] == 'C')
	{
		swap->map[swap->file.y][swap->file.x] = '0';
		swap->file.colects--;
	}
	if (swap->map[swap->file.y + 1][swap->file.x] == 'E')
	{
		if (swap->file.colects == 0)
		{
			game_over(swap);
			return (1);
		}
	}
	return (0);
}

int	move_up(t_swap *swap)
{
	mlx_clear_window (swap->mlx.mlx, swap->mlx.win);
	if (swap->map[swap->file.y - 1][swap->file.x] != '1' &&
			swap->map[swap->file.y - 1][swap->file.x] != 'E')
	{
		swap->file.y--;
		swap->moves++;
		printf("moves = %d\n", swap->moves);
	}
	if (swap->map[swap->file.y][swap->file.x] == 'C')
	{
		swap->map[swap->file.y][swap->file.x] = '0';
		swap->file.colects--;
	}
	if (swap->map[swap->file.y - 1][swap->file.x] == 'E')
	{
		if (swap->file.colects == 0)
		{
			game_over(swap);
			return (1);
		}
	}
	return (0);
}
