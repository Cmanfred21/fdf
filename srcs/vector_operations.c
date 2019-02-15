/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:37:15 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/13 16:45:05 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vector	vector_pos(t_map *map, int x, int y)
{
	return (((*map)->vectors)[y * (map->width) + x]);
}

void	ft_minmax(t_map *map)
{
	int			min;
	int			max;
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

t_vector	project_vector(t_vector v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->min + mlx->map->max)/ 2.0f;
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}
