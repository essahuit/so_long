/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:04:43 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 13:02:19 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_perror(int n)
{
	if (n == 0)
		ft_putstr_fd("Error : map must be closed\n", 2);
	else if (n == 1)
		ft_putstr_fd("Error : map must contain 1 starting position\n", 2);
	else if (n == 2)
		ft_putstr_fd("Error : map must contain at least 1 collectible\n", 2);
	else if (n == 3)
		ft_putstr_fd("Error : map must contain at least 1 exit\n", 2);
	else if (n == 4)
		ft_putstr_fd("Error : image not found", 2);
	else if (n == 5)
		ft_putstr_fd("Error : mlx error", 2);
	else if (n == 6)
		ft_putstr_fd("Error : window error", 2);
	else if (n == 7)
		ft_putstr_fd("Error : invalid character", 2);
	exit(1);
}

int	ft_ar_size(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	return (i);
}

int	ft_check_path(const char *big, const char *small)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!big)
		return (0);
	len = ft_strlen(small);
	i = 0;
	while (i <= ft_strlen(big))
	{
		if (big[i] == small[0])
		{
			j = 0;
			while (big[i + j] == small[j] && j <= len)
				j++;
			if (j == ft_strlen(small) + 1)
				return (1);
		}
		i++;
	}
	return (0);
}
