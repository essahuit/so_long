/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:51:55 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 14:42:42 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#define X 32

void	ft_mlx_image(char **ar, t_data *data, int i, int j)
{
	if (ar[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall, j * 32, i * 32);
	else if (ar[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, j * 32, i * 32);
		data->player_x = j;
		data->player_y = i;
	}
	else if (ar[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->door, j * 32, i * 32);
		data->door_x = j;
		data->door_y = i;
	}
	else if (ar[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->coin, j * X, i * X);
		data->collect++;
	}
	else if (ar[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, j * 32, i * 32);
}

void	ft_mlx_put_image(char **ar, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j] != '\n')
		{
			ft_mlx_image(ar, data, i, j);
			j++;
		}
		i++;
	}
}

void	ft_mlx_key_second(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->ground,
		(data->player_x + x) * 32, (data ->player_y + y) * 32);
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		(data->player_x + x) * 32, (data ->player_y + y) * 32);
	mlx_put_image_to_window(data->mlx, data->win, data->ground,
		(data->player_x) * 32, (data ->player_y) * 32);
	data->a[data->player_y][data->player_x] = '0';
	data->player_y = data->player_y + y;
	data->player_x = data->player_x + x;
	if (data->a[data->player_y][data->player_x] == 'C')
		data->collect--;
	data->a[data->player_y][data->player_x] = 'P';
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_mlx_key(t_data *data, int x, int y)
{
	if (data->a[data->player_y + y][data->player_x + x] == 'E' &&
		data->collect == 0)
	{
		data->moves++;
		mlx_clear_window(data->mlx, data->win);
		ft_putnbr_fd(data->moves, 1);
		ft_putchar_fd('\n', 1);
		exit (1);
	}
	if (data->a[data->player_y + y][data->player_x + x] != 'E')
		ft_mlx_key_second(data, x, y);
}

void	ft_mlx(char **ar, int y, int x)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_perror(5);
	data.win = mlx_new_window(data.mlx, x * 32, y * 32, "so_long");
	if (data.win == NULL)
		ft_perror(5);
	data.wall = mlx_xpm_file_to_image(data.mlx, "wall.xpm", &x, &x);
	data.door = mlx_xpm_file_to_image(data.mlx, "door.xpm", &x, &x);
	data.player = mlx_xpm_file_to_image(data.mlx, "player.xpm", &x, &x);
	data.ground = mlx_xpm_file_to_image(data.mlx, "ground.xpm", &x, &x);
	data.coin = mlx_xpm_file_to_image(data.mlx, "coin.xpm", &x, &x);
	if (data.wall == NULL || data.door == NULL || data.player == NULL
		|| data.ground == NULL || data.coin == NULL)
		ft_perror(4);
	data.a = ar;
	data.collect = 0;
	data.moves = 0;
	ft_mlx_put_image(ar, &data);
	mlx_key_hook(data.win, ft, &data);
	mlx_hook(data.win, 17, 0, ftt, &data);
	mlx_loop(data.mlx);
}
