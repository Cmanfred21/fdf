/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:53:50 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/19 18:33:21 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/fdf.h"

int				ft_clean(t_list **head, t_map **map)
{
	t_list	*next;
	int		i;

	i = -1;
	if (head)
		while (*head)
		{
			next = (*head)->next;
			ft_memdel(&((*head)->content));
			ft_memdel((void **)head);
			*head = next;
		}
	if (map)
	{
		while (++i < (*map)->width * (*map)->height)
			ft_memdel((void **)&((*map)->vectors)[i]);
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
		if ((tmp[i] > '9' || tmp[i] < '0') && tmp[i] != ' ' && tmp[i] != 'x'
				&& (tmp[i] > 'F' || tmp[i] < 'A') && tmp[i] != '-' && tmp[i] != ',')
		{
			ft_putendl("incorrect symbols");
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
	int		flag;

	curr = *head;
	flag = 0;
	est = -1;
	while (get_next_line(fd, &tmp))
	{
		if (est == -1)
			est = ft_countwords(tmp, ' ');
		else if (ft_countwords(tmp, ' ') != est || ft_checkmap(tmp))
		{
			ft_putendl ("incorrect length");
			flag++;
		}
		((*map)->height)++;
		curr = ft_lstnew(tmp, ft_strlen(tmp) + 1);
		ft_lstadd(head, curr);
		ft_strdel(&tmp);
	}
	if (flag)
		return (1);
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
	int		pos;

	tmp = *head;
	y = -1;
	while (++y < (*map)->height)
	{
		x = -1;
		split = ft_strsplit(tmp->content, ' ');
		while (++x < (*map)->width)
		{
			pos = y * (*map)->width + x;
			(((*map)->vectors)[pos]) = ft_memalloc(sizeof(t_vector));
			(((*map)->vectors)[pos])->z = (double)ft_atoi(split[x]);
			(((*map)->vectors)[pos])->y = (double)y;
			(((*map)->vectors)[pos])->x = (double)x;
		}
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
	(*map)->vectors = ft_memalloc(sizeof(t_vector *)
			* (*map)->width * (*map)->height);
	if (ft_mapconv(&head, map))
		return (ft_clean(&head, map));
	ft_clean(&head, NULL);
	return (0);
}
