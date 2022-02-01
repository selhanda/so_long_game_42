/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:38:51 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 15:16:52 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	init_img(t_imgs *i, t_root *v)
{
	i->exit.img = mlx_new_image(v->mlx, 60, 60);
	i->exit.img = mlx_xpm_file_to_image(v->mlx, D, &i->exit.w, &i->exit.h);
	i->coin.img = mlx_new_image(v->mlx, 60, 60);
	i->coin.img = mlx_xpm_file_to_image(v->mlx, C, &i->coin.w, &i->coin.h);
	i->player.img = mlx_new_image(v->mlx, 60, 60);
	i->player.img = mlx_xpm_file_to_image(v->mlx,
			P, &i->player.w, &i->player.h);
	i->wall.img = mlx_new_image(v->mlx, 60, 60);
	i->wall.img = mlx_xpm_file_to_image(v->mlx, W, &i->wall.w, &i->wall.h);
}

void	init_swap(t_root *vars, t_file *file, t_imgs *img, t_swap *swap)
{
	swap->mlx = *vars;
	swap->file = *file;
	swap->img = *img;
	swap->moves = 0;
}

void	norm(int *i, int *y, t_imgs *m, t_root *v)
{
	*i = 0;
	*y = 0;
	init_img(m, v);
}

void	putmap(t_root v, char **map, t_imgs m, t_file f)
{
	int	i;
	int	j;
	int	x;
	int	y;

	norm(&i, &y, &m, &v);
	while (y <= (f.line_count - 1) * 60)
	{
		j = 0;
		x = 0;
		while (x <= (f.line_len - 1) * 60)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window (v.mlx, v.win, m.wall.img, x, y);
			else if (map[i][j] == 'P')
				draw_player(v, m, f);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window (v.mlx, v.win, m.exit.img, x, y);
			if (map[i][j++] == 'C')
				mlx_put_image_to_window (v.mlx, v.win, m.coin.img, x, y);
			x += 60;
		}
		y += 60;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	int		fd;
	char	**map;

	if (argc != 2)
		error_1();
	if (argc == 2)
	{
		check_file(argv[1]);
		init_file(&swap.file);
		fd = open(argv[1], O_RDWR);
		map = ft_malloc_map(fd, &swap.file);
		close(fd);
		fd = open(argv[1], O_RDWR);
		map = ft_get_map(fd, map, &swap.file);
		swap.mlx.mlx = mlx_init();
		swap.mlx.win = mlx_new_window(swap.mlx.mlx,
				(swap.file.line_len - 1) * N, (swap.file.line_count) * N, "s!");
		swap.map = map;
		init_swap(&swap.mlx, &swap.file, &swap.img, &swap);
		putmap(swap.mlx, map, swap.img, swap.file);
		mlx_hook(swap.mlx.win, 2, 1L << 0, move_f, &swap);
		mlx_hook(swap.mlx.win, 17, 0L, des_b, &swap.mlx);
		mlx_loop(swap.mlx.mlx);
	}
}
