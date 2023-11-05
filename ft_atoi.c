/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:25:23 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/31 17:51:01 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = get_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && result > (LLONG_MAX - (str[i] - '0')) / 10)
			return (-1);
		else if (sign == -1 && result > (LLONG_MAX - (str[i] - '0')) / 10)
			return (0);
		result = (result * 10) + (str[i++] - '0');
	}
	return (sign * (int)result);
}
