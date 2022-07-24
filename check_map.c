/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:05:13 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 12:58:32 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_check_map(char **ar, int j)
{
	if (ft_check(ar, 'P') != 1)
		ft_perror(1);
	if ((ft_check(ar, 'C') < 1))
		ft_perror(2);
	if ((ft_check(ar, 'E') < 1))
		ft_perror(3);
	ft_check_line(ar, ar[0]);
	ft_check_wall(ar, '1', j);
	ft_check_char(ar, "01ECP");
}

void	ft_check_char(char **ar, char *s)
{
	int	i;
	int	j;
	int	k;
	int	flag;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j] != '\n' && ar[i][j])
		{
			flag = 0;
			k = 0;
			while (s[k])
			{
				if (ar[i][j] == s[k])
					flag++;
				k++;
			}
			if (flag == 0)
				ft_perror(7);
			j++;
		}
		i++;
	}
}

int	ft_check(char **ar, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j] != '\n')
		{
			if (ar[i][j] == c)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

void	ft_check_line(char **ar, char *s)
{
	int	j;

	j = 0;
	while (ar[j])
	{
		if (ft_strlen(ar[j]) != ft_strlen(s))
			ft_perror(2);
		j++;
	}
}

void	ft_check_wall(char **ar, char c, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (ar[0][i] != '\n')
	{
		if (ar[0][i] != c)
			ft_perror(0);
		if (ar[j - 1][i] != c)
			ft_perror(0);
		i++;
	}
	while (ar[k])
	{
		if (ar[k][0] != c)
			ft_perror(0);
		if (ar[k][i - 1] != c)
			ft_perror(0);
		k++;
	}
}
