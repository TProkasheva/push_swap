/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:30:06 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	dlen = i;
	while (src[i - dlen] && i < size - 1)
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (dlen < size)
		dst[i] = '\0';
	return (dlen + ft_strlen(src));
}
