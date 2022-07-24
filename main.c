/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:12:00 by kessalih          #+#    #+#             */
/*   Updated: 2022/07/24 14:17:23 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**ar;
	int		j;

	fd = open(argv[1], O_RDONLY);
	j = -1;
	if (argc != 2 || !ft_check_path(argv[1], ".ber"))
		ft_perror(ft_check_path(argv[1], ".ber"));
	i = ft_ar_size(fd);
	ar = malloc(sizeof(char *) * (i + 1));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (++j < i)
		ar[j] = get_next_line(fd);
	ar[j] = NULL;
	close(fd);
	ft_check_map(ar, j);
	ft_mlx(ar, j, (ft_strlen(ar[0]) - 1));
	return (0);
}
