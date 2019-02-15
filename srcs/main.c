/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:50:42 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/13 15:26:46 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
//#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../includes/fdf.h"

static int	ft_return(char *str)
{
	ft_putendl(str);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
//	t_mlx	*mlx;

	if (argc != 2)
		return (ft_return("usage: fdf input_file"));
	fd = open(argv[1], O_RDONLY);
	if (ft_mapread(fd, &map))
		return(ft_return("map error"));
//	mlx->map = map;
	ft_clean(NULL, &map);
	return (0);
	//	mlx->init = mlx_init();
	//	mlx->window = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	//	mlx_loop(mlx_ptr);
}
