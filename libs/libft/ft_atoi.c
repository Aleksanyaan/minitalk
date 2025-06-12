/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:44:05 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/21 19:45:05 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static void	check_zeros(const char *str, int i, long int res)
{
	while (str[i] && str[i] == '0')
	{
		if (str[i] == '\0' && str[i - 1] == '0')
			res = str[i - 1] - '0';
		i++;
	}
}

long int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	check_zeros(str, i, res);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
