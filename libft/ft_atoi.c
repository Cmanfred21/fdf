/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:58:33 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/10 16:57:52 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					i;
	long long int		res;
	long long int		neg;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\n' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
	}
	else
		i--;
	while (str[++i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		res *= 10;
		res += str[i] - '0';
	}
	res *= neg;
	return ((int)res);
}
