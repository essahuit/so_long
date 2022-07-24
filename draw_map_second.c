/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:15:52 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 15:19:45 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft(int keysym, t_data *data)
{
	if ((keysym == 13 || keysym == 126)
		&& data->a[data->player_y - 1][data->player_x] != '1')
		ft_mlx_key(data, 0, -1);
	else if ((keysym == 0 || keysym == 123)
		&& data->a[data->player_y][data->player_x - 1] != '1')
		ft_mlx_key(data, -1, 0);
	else if ((keysym == 1 || keysym == 125)
		&& data->a[data->player_y + 1][data->player_x] != '1')
		ft_mlx_key(data, 0, 1);
	else if ((keysym == 2 || keysym == 124)
		&& data->a[data->player_y][data->player_x + 1] != '1')
		ft_mlx_key(data, 1, 0);
	else if (keysym == 53)
	{
		mlx_clear_window(data->mlx, data->win);
		exit(0);
	}
	return (1);
}

int	ftt(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	exit(0);
}
