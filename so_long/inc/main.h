/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:41:40 by selhanda          #+#    #+#             */
/*   Updated: 2021/12/21 19:54:13 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define BUFFER_SIZE 1
# define C "asset/coin.xpm"
# define P "asset/player.xpm"
# define D "asset/door.xpm"
# define W "asset/wall.xpm"
# define L 12527386
# define N 60

typedef struct s_file
{
	int	line_count;
	int	line_len;
	int	player;
	int	colects;
	int	exit_d;
	int	x;
	int	y;
}	t_file;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_imgs
{
	t_img	player;
	t_img	coin;
	t_img	wall;
	t_img	floor;
	t_img	exit;
}	t_imgs;

typedef struct s_root
{
	void	*mlx;
	void	*win;
}	t_root;

typedef struct s_swap
{
	t_root	mlx;
	t_file	file;
	t_imgs	img;
	char	**map;
	int		moves;
}	t_swap;

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	error_1(void);
void	check_file(char *str);
char	**ft_malloc_map(int fd, t_file *file);
void	init_file(t_file *file);
char	**ft_get_map(int fd, char **map, t_file *file);
int		is_w_e(char c, t_file *file, int i, int j);
void	ft_check_map(char **map, t_file *file);
void	v_map_e(t_file *file, char **map);
void	ft_putstr(char *err);
void	free_map(char **map, int line, char *error);
void	putmap(t_root vars, char **map, t_imgs img, t_file file);
int		move_f(int keycode, t_swap *swap);
int		move_right(t_swap *swap);
int		move_left(t_swap *swap);
int		move_down(t_swap *swap);
int		move_up(t_swap *swap);
void	close_win(t_root *vars);
void	game_over(t_swap *s);
void	init_img(t_imgs *i, t_root *v);
void	init_swap(t_root *vars, t_file *file, t_imgs *img, t_swap *swap);
int		des_b(t_root *mlx);
char	*ft_itoa(int n);
void	norm(int *i, int *y, t_imgs *m, t_root *v);
void	draw_player(t_root v, t_imgs m, t_file f);

#endif
