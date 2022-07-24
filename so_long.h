/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:54:14 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 14:20:17 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*door;
	void	*player;
	void	*coin;
	void	*ground;
	int		player_x;
	int		player_y;
	char	**a;
	int		door_x;
	int		door_y;
	int		collect;
	int		moves;
}	t_data;

void	ft_perror(int n);
int		ft_check(char **ar, char c);
void	ft_check_line(char **ar, char *s);
void	ft_check_wall(char **ar, char c, int j);
void	ft_check_map(char **ar, int j);
void	ft_mlx_key(t_data *data, int x, int y);
void	ft_mlx_key_second(t_data *data, int x, int y);
int		ft(int keysym, t_data *data);
int		ftt(t_data *data);
void	ft_mlx_image(char **ar, t_data *data, int i, int j);
void	ft_mlx_put_image(char **ar, t_data *data);
void	ft_mlx(char **ar, int m, int h);
int		ft_ar_size(int fd);
int		ft_check_path(const char *bog, const char *small);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_check_char(char **ar, char *s);
#endif
