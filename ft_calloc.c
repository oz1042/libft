/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:28:51 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/31 17:55:14 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	if (size != 0 && count > (SIZE_MAX / size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = count * size;
	if (size == 0 || i == 0)
		s = malloc(1);
	else
		s = malloc(i);
	if (s == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(s, i);
	return (s);
}
