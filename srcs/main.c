/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:50:42 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/10 19:16:57 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
//#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../includes/fdf.h"

static void	ft_clean(t_map **map)
{
	int		**res;
	int		i;

	res = (*map)->tab;
	i = 0;
	while (i < (*map)->height)
	{
		free(res[i]);
		i++;
	}
	free(res);
	free(*map);
}

int	main(int argc, char **argv)
{
//	void	*mlx_ptr;
//	void	*win_ptr;
	int		fd;
	int		i;
	int		j;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	if (argc != 2)
	{
		ft_putendl("usage: fdf input file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (ft_mapread(fd, &(map->tab), &(map->width), &(map->height)))
	{
		ft_putendl("map error");
		ft_clean(&map);
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_putnbr((map->tab)[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_clean(&map);
	return (0);
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, argv[1]);
//	mlx_loop(mlx_ptr);
}
