/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:37:15 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/21 18:24:37 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

/*
** Function, that project points on the screen so it will look like 3D-model
** Also, there is additional function for iso-projection, because I haven't
** thought out how to rotate iso-projection
*/

static t_vector	rotate(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z * r->zscale;
	y = p.y;
	if (r->iso == 1)
	{
		v.x = (x - y) * cos(0.523599);
		v.y = -z + (x + y) * sin(0.523599);
		v.z = p.z;
		v.color = p.color;
		return (v);
	}
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

/*
** User-friendly function, that returns needed element from massive of
** structures, using only X and Y coordinates of the point
*/

t_vector		vector_pos(t_map *map, int x, int y)
{
	return (*((map->vectors)[y * map->width + x]));
}

/*
** Function, that calculates the lowest and the highest point of the map.
** Usefull for gradient coloring only
*/

void			ft_minmax(t_map *map)
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
			if ((int)v.z < map->min)
				map->min = (int)v.z;
			if ((int)v.z > map->max)
				map->max = (int)v.z;
		}
	}
	if (map->min < 0 || map->max < 0)
		ft_z_zero(&map);
}

/*
** Function, that fills the point with the needed color, according to its
** altitude
*/

static int		ft_fill_color(t_vector *v, t_mlx *mlx)
{
	int		res;

	res = ((255 * v->z) / (mlx->map->max - mlx->map->min));
	return (res << 16 | res << 8 | 255);
}

/*
** Function, that rotates the map, formates the map with scale and
** offset variables and place the map somewhere in the middle of the screen
*/

t_vector		project_vector(t_vector v, t_mlx *mlx)
{
	v.color = ft_fill_color(&v, mlx);
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1) / 2.0f;
	v.z -= (double)(mlx->map->min + mlx->map->max) / 2.0f;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}
