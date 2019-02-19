/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:37:15 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/19 18:21:44 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static t_vector	rotate(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = sin(r->y) * x - cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

t_vector	vector_pos(t_map *map, int x, int y)
{
	return (*((map->vectors)[y * map->width + x]));
}

void	ft_minmax(t_map *map)
{
	int			x;
	int			y;
	t_vector	v;

	map->min = 2147483647;
	map->max = -2147483648;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			v = vector_pos(map, x, y);
			if (v.z < map->min)
				map->min = v.z;
			if (v.z > map->max)
				map->max = v.z;
		}
	}
}

static int	ft_fill_color(t_vector *v, t_mlx *mlx)
{
	int		res;

	res = ((255 * v->z) / (mlx->map->max - mlx->map->min));
	 return (res << 16 | res << 8 | 255);
}

t_vector	project_vector(t_vector v, t_mlx *mlx)
{
	v.color = ft_fill_color(&v, mlx);
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1)/ 2.0f;
	v.z -= (double)(mlx->map->min + mlx->map->max) / 2.0f;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}
