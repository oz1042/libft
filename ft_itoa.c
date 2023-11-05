/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:43:58 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/31 17:57:12 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	len;

	len = 1;
	while (n > 9 || n < -9)
	{
		len++;
		n = n / 10;
	}
	if (n < 0)
		len++;
	return (len);
}

static char	*secure_int_min(void)
{
	char	*result;

	result = ft_calloc(12, 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}

static char	*allocate_memory(int len)
{
	char	*result;

	result = ft_calloc(len + 1, 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	return (result);
}

static void	convert_int_to_char(int n, char *result, int len)
{
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (len > 0)
	{
		len--;
		if (len != 0 || result[0] != '-')
			result[len] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = get_length(n);
	if (n == INT_MIN)
		return (secure_int_min());
	result = allocate_memory(len);
	if (result == NULL)
		return (NULL);
	convert_int_to_char(n, result, len);
	return (result);
}
