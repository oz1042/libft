/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:07:33 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/17 07:57:39 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	int				direction;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	direction = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src)
	{
		direction = -1;
		d += len - 1;
		s += len - 1;
	}
	while (i < len)
	{
		*d = *s;
		d += direction;
		s += direction;
		i++;
	}
	return (dst);
}
