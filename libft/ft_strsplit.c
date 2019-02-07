/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:30:46 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/04 13:01:34 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	*ft_countc(const char *s, char c, int len, int words)
{
	int		i;
	int		*lens;
	int		count;
	int		j;

	i = 0;
	j = 0;
	lens = (int*)malloc(sizeof(int) * words);
	while (i < len && s[i])
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		lens[j] = count;
		j++;
	}
	return (lens);
}

static int	ft_count(const char *s, char c, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (1);
	while (i < len && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**ft_mal(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	int		len;
	int		*lens;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_count(s, c, len)))))
		return (NULL);
	i = 0;
	j = 0;
	lens = ft_countc(s, c, len, ft_count(s, c, len));
	while (i < ft_count(s, c, len))
	{
		if (!(res[i] = (char*)malloc(sizeof(char) * (lens[i]) + 1)))
		{
			free(res);
			free(lens);
			return (NULL);
		}
		i++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	if (!(res = ft_mal(s, c)))
		return (NULL);
	while (i < ft_count(s, c, ft_strlen(s) - 1))
	{
		k = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
		{
			res[i][k] = s[j];
			j++;
			k++;
		}
		res[i][k] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
