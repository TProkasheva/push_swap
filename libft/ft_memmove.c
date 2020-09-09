/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:27:03 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t length)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	src1 = (char*)src;
	dst1 = (char*)dst;
	if (!src1 && !dst1)
		return (NULL);
	i = 0;
	if (src > dst)
		while (i < length)
		{
			dst1[i] = src1[i];
			i++;
		}
	else
		while (length--)
			dst1[length] = src1[length];
	return (dst1);
}
