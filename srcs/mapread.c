/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:53:50 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/10 20:38:19 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

static int		ft_mapconv(int ***map, int *i, int *j, char *tmp)
{
	char	**prenum;

	(*map)[*i] = (int *)malloc(sizeof(int) * (ft_countwords(tmp, ' ')));
	prenum = ft_strsplit(tmp, ' ');
	while (prenum[++(*j)])
		(*map)[*i][*j] = ft_atoi(prenum[*j]);
	(*i)++;
	ft_free2darr(prenum);
	ft_strdel(&tmp);

}

int				ft_mapread(int fd, int ***map, int *width, int *height)
{
	int		i;
	int		j;
	char	*tmp;
	int		est;

	i = 0;
	if (fd < 0)
		return (1);
	est = -1;
	*map = (int **)malloc(sizeof(int *) * 10000);
	while (get_next_line(fd, &tmp))
	{
		j = -1;
		if (est == -1)
			est = ft_countwords(tmp, ' ');
		if (ft_mapconv(map, &i, &j, tmp))
			est = -2;
		*height = i;
		if (j != est)
			return (1);
	}
	*width = j;
	return (0);
}
