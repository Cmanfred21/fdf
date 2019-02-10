/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:12:56 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/10 19:14:25 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

int				ft_mapread(int fd, int ***map, int *width, int *height);

typedef struct	s_map
{
	int			**tab;
	int			height;
	int			width;
}				t_map;
#endif
