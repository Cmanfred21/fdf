/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:17:14 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/20 21:24:25 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static int		checkeof(int ret, int fd, t_list **head, char **line)
{
	t_list	*res;
	t_list	*pres;

	pres = *head;
	res = *head;
	while (res)
	{
		if ((int)res->content_size == fd)
			break ;
		pres = res;
		res = res->next;
	}
	if (ret < BUFF_SIZE && !ft_strlen(res->content))
	{
		pres->next = res->next;
		free(res->content);
		free(res);
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static t_list	*create_elem(t_list **head, const int fd)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(head, tmp);
	return (tmp);
}

static void		*contentmove(char *content, int count)
{
	int		i;
	char	*tmp;

	i = count + 1;
	tmp = ft_memalloc(ft_strlen(content) - count + 1);
	while (content[i])
	{
		tmp[i - count - 1] = content[i];
		i++;
	}
	free(content);
	return ((void *)tmp);
}

static void		ft_realloc(char *buff, t_list *res, int ret)
{
	char			*tmp;

	buff[ret] = '\0';
	tmp = ft_strjoin((char *)res->content, buff);
	free(res->content);
	res->content = (void *)tmp;
}

int				get_next_line(const int fd, char **line)
{
	int				count;
	static t_list	*head;
	t_list			*res;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if ((fd < 0 || (!(line)) || read(fd, buff, 0) < 0))
		return (-1);
	res = create_elem(&head, fd);
	CHECKMALLOC((*line = ft_strnew(0)));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		ft_realloc(buff, res, ret);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (checkeof(ret, fd, &head, line))
		return (0);
	count = ft_copyuntil(line, res->content, '\n');
	if (ret != 0 || ft_strcmp(res->content, *line))
		res->content = contentmove((char *)res->content, count);
	else
		((char *)res->content)[0] = '\0';
	return (1);
}
