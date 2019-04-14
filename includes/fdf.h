/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:12:56 by cmanfred          #+#    #+#             */
/*   Updated: 2019/04/14 19:40:10 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bitspp;
	int			string;
	int			endian;
}				t_image;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_line
{
	t_vector	start;
	t_vector	finish;
	int			dx;
	int			dy;
	int			sy;
	int			sx;
	double		fau;
}				t_line;

typedef struct	s_map
{
	t_vector	**vectors;
	int			height;
	int			width;
	int			min;
	int			max;
}				t_map;

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	double		scale;
	double		zscale;
	int			iso;
}				t_cam;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			prevx;
	int			prevy;
	int			down;
}				t_mouse;

typedef struct	s_mlx
{
	t_map		*map;
	void		*init;
	void		*window;
	t_image		*image;
	t_cam		*cam;
	t_mouse		*mouse;
}				t_mlx;

int				ft_mapread(int fd, t_map **map);

int				ft_clean(t_list **head, t_map **map);

void			ft_cut_off(t_vector *pt1, t_vector *pt2);

void			image_set_pixel(t_image *image, int x, int y, int color);

t_image			*ft_delimage(t_mlx *mlx, t_image *img);

t_mlx			*init(char *file);

void			ft_putimage(t_mlx *mlx);

t_vector		project_vector(t_vector v, t_mlx *mlx);

void			ft_minmax(t_map *map);

t_vector		vector_pos(t_map *map, int x, int y);

t_image			*new_image(t_mlx *mlx);

int				ft_mouse_move(int x, int y, t_mlx *mlx);

int				ft_mouse_up(int but, int x, int y, t_mlx *mlx);

int				ft_mouse_down(int but, int x, int y, t_mlx *mlx);

void			ft_z_zero(t_map **map);

#endif
