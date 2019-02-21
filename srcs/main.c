/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:50:42 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/21 22:12:17 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../includes/fdf.h"

void		ft_z_zero(t_map **map)
{
	int			x;
	int			y;
	t_vector	*v;

	y = -1;
	while (++y < (*map)->height)
	{
		x = -1;
		while (++x < (*map)->width)
		{
			v = ((*map)->vectors)[y * (*map)->width + x];
			v->z -= (*map)->min;
		}
	}
	(*map)->max -= (*map)->min;
	(*map)->min = 0;
}

/*
** Function, that hooks ESC to close the
** window and I to make an iso-proection of the map
*/

static int	hook_keydown(int key, t_mlx **mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 34)
	{
		if ((*mlx)->cam->iso == 0)
			(*mlx)->cam->iso++;
		else if ((*mlx)->cam->iso == 1)
			(*mlx)->cam->iso--;
	}
	ft_putimage(*mlx);
	return (0);
}

/*
** Function, that prints string str, followed by \n and exits
*/

static int	ft_return(char *str)
{
	ft_putendl(str);
	exit(0);
}

/*
** main, that checks valid argument, reads and checks the map,
** initializes mlx structure, renders first image and then hooks
** all needed keys and events
*/

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (ft_return("usage: fdf input_file"));
	fd = open(argv[1], O_RDONLY);
	if (ft_mapread(fd, &map))
		return (ft_return("map error"));
	if ((mlx = init(argv[1])) == NULL)
		return (1);
	mlx->map = map;
	if ((WIN_WIDTH / map->width) < (WIN_HEIGHT / map->height))
		mlx->cam->scale = (WIN_WIDTH / map->width) / 2;
	else
		mlx->cam->scale = (WIN_HEIGHT / map->height) / 2;
	ft_putimage(mlx);
	mlx_key_hook(mlx->window, hook_keydown, &mlx);
	mlx_hook(mlx->window, 4, 0, ft_mouse_down, mlx);
	mlx_hook(mlx->window, 5, 0, ft_mouse_up, mlx);
	mlx_hook(mlx->window, 6, 0, ft_mouse_move, mlx);
	mlx_loop(mlx->init);
	return (0);
}
