/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:24:25 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/19 18:32:56 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->init, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(char *file)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->init = mlx_init()) == NULL ||
			(mlx->window = mlx_new_window(mlx->init, WIN_WIDTH,
										  WIN_HEIGHT, file)) == NULL ||
			(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
			(mlx->image = new_image(mlx)) == NULL)
		return (mlxdel(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = -0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	return (mlx);
}
