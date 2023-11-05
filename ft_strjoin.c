/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:39:56 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/17 07:40:39 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = ft_calloc(len_s1 + len_s2 + 1, 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, len_s1);
	ft_memcpy(s3 + len_s1, s2, len_s2);
	s3[len_s1 + len_s2] = '\0';
	return (s3);
}
