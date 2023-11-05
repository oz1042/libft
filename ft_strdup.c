/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:38:32 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/31 17:41:49 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}
