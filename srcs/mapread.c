/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:53:50 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/11 20:01:09 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/fdf.h"

static int		ft_clean(t_list **head, t_map **map)
{
	t_list	*next;

	while (*head)
	{
		next = (*head)->next;
		ft_memdel(&((*head)->content));
		ft_memdel((void **)head);
	}
	if (map && *map)
	{
		ft_memdel((void **)&((*map)->vectors));
		ft_memdel((void **)map);
	}
	return (1);
}

static int		ft_checkmap(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[++i] != '\0')
	{
		if ((tmp[i] > '9' || tmp[i] < '0') && tmp[i] != ' ')
		{
			ft_strdel(&tmp);
			return (1);
		}
	}
	return (0);
}

static int		ft_lstfill(int fd, t_list **head, t_map **map)
{
	t_list	*curr;
	char	*tmp;
	int		est;

	curr = *head;
	est = -1;
	while (get_next_line(fd, &tmp))
	{
		if (est == -1)
			est = ft_countwords(tmp, ' ');
		else if (ft_countwords(tmp, ' ') != est || ft_checkmap(tmp))
			return (1);
		((*map)->height)++;
		curr = ft_lstnew(tmp, ft_strlen(tmp) + 1);
		ft_lstadd(head, curr);
		ft_strdel(&tmp);
	}
	(*map)->width = est;
	ft_lstrev(head);
	return (0);
}

static int		ft_mapconv(t_list **head, t_map **map)
{
	int		x;
	int		y;
	t_list	*tmp;
	char	**split;

	tmp = *head;
	y = 0;
	while (y < (*map)->height)
	{
		x = -1;
		split = ft_strsplit(tmp->content, ' ');
		while (++x < (*map)->width)
		{
			(((*map)->vectors)[y * (*map)->width + x]) = ft_memalloc(sizeof(t_vector));
			(((*map)->vectors)[y * (*map)->width + x])->z = (double)ft_atoi(split[x]);
			(((*map)->vectors)[y * (*map)->width + x])->y = (double)y;
			(((*map)->vectors)[y * (*map)->width + x])->x = (double)x;
		}
		y++;
		tmp = tmp->next;
		ft_free2darr(split);
	}
	return (0);
}

int				ft_mapread(int fd, t_map **map)
{
	t_list	*head;

	head = NULL;
	if (fd < 0)
		return (1);
	*map = ft_memalloc(sizeof(t_map));
	if (ft_lstfill(fd, &head, map) == 1)
		return (ft_clean(&head, map));
	(*map)->vectors = ft_memalloc(sizeof(t_vector *) * (*map)->width * (*map)->height);
	if (ft_mapconv(&head, map))
		return (ft_clean(&head, map));
	return (0);
}
