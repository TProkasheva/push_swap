/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:31:15 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	int	i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(substr);
	if (!len)
		return ((char*)str);
	while (str[i])
	{
		while ((str[i + j] == substr[j]) && ((i + j) < (int)n))
		{
			if (j == len - 1)
				return ((char*)(str + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
