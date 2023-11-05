/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:39:22 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/17 07:39:32 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		len = 0;
	else if (len > i - start)
		len = i - start;
	str = ft_calloc(len + 1, 1);
	if (str != NULL)
	{
		ft_memcpy(str, &s[start], len);
		str[len] = '\0';
	}
	return (str);
}
