/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:31:46 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:54 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*dst;
	unsigned int		i;

	i = 0;
	if (len > len + 1)
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (dst);
}
