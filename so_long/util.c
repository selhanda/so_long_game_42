/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:19:19 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 14:41:18 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	close_win(t_root *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

void	game_over(t_swap *s)
{
	int		x;
	int		y;

	x = (s->file.line_len * 60) / 2;
	y = (s->file.line_count * 60) / 2;
	mlx_clear_window(s->mlx.mlx, s->mlx.win);
	mlx_string_put(s->mlx.mlx, s->mlx.win, x, y, 255, "YOU WIN! PRESS ESC");
}

int	des_b(t_root *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
}

void	draw_player(t_root v, t_imgs m, t_file f)
{
	mlx_put_image_to_window(v.mlx, v.win, m.player.img, f.x * N, f.y * N);
}
