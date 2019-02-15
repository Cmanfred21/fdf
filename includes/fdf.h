/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:12:56 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/15 17:57:06 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"

# define WIN_WIDTH = 1920;
# define WIN_HEIGHT = 1080;

typedef struct	s_image
{
	void		*ptr;
	int			*bitspp;
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
	int			sx;
	int			sy;
	int			fau;
	int			fauconst;
}				t_line;

typedef struct	s_map
{
	t_vector	**vectors;
	int			height;
	int			width;
}				t_map;

typedef struct	s_mlx
{
	t_map		*map;
	void		*init;
	void		*window;
	t_image		*image;
}				t_mlx;

int             ft_mapread(int fd, t_map **map);

int				ft_clean(t_list **head, t_map **map);

#endif
