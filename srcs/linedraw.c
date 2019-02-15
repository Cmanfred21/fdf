/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:06:03 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/15 19:52:57 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_make_bresenham(t_mlx *mlx, t_line *line, t_vector *pt1, t_vector *pt2)
{


static void	ft_drawline(t_mlx *mlx, t_vector pt1, t_vector pt2)
{
	t_line	line;

	line.start = pt1;
	line.finish = pt2;
	line.dx = (int)ft_module((int)(pt1.x) - (int)(pt2.x));
	line.dy = (int)ft_module((int)(pt1.y) - (int)(pt2.y));
	line.sx = d.x / ((int)(pt1.x) - (int)(pt2.x));
	line.sy = d.y / ((int)(pt1.y) - (int)(pt2.y));
	line.fau = (line.dx > line.dy? line.dx : -line.dy) / 2;
	ft_cut_off(&pt1, &pt2);
	while (!((int)(pt1.x) == (int)(pt2.x) && (int)(pt1.y) == (int)(pt2.y)))
		if (ft_make_bresenham(mlx, &line, &pt1, &pt2))
			break ;
}

void		ft_putimage(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	y = -1;
	ft_bzero(mlx->image->ptr, WIN_WIDTH * WIN_HEIGHT * mlx->image->bitspp);
	ft_minmax(map);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			v = project_vector(vector_pos(map, x, y), mlx);
			if (x + 1 < map->width)
				ft_drawline(mlx, v, project_vector(vector_pos(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				ft_drawline(mlx, v, project_vector(vector_pos(map, x, y + 1), mlx));
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->ptr, 0, 0);
}
