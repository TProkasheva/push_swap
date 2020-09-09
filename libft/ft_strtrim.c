/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:31:53 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		beginlen;
	int		endlen;
	int		len;

	if (!s)
		return (NULL);
	beginlen = 0;
	while (s[beginlen] == ' ' || s[beginlen] == '\t' || s[beginlen] == '\n')
		beginlen++;
	len = ft_strlen(s);
	endlen = 0;
	while (s[len - endlen - 1] == ' '
			|| s[len - 1 - endlen] == '\t' || s[len - endlen - 1] == '\n')
		endlen++;
	len = len - beginlen - endlen;
	if (len <= 0)
		len = 0;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strncpy(dst, &(s[beginlen]), len);
	dst[len] = '\0';
	return (dst);
}
