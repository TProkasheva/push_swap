/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:31:31 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:55 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nword(char const *s, char c)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static int	ft_lenword(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_delstrsplit(char ***buf, int i)
{
	while (i--)
	{
		free(*buf[i]);
		*buf[i] = NULL;
	}
	free(*buf);
	*buf = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**buf;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	if (!(buf = (char**)malloc(sizeof(char*) * (ft_nword(s, c) + 1))))
		return (NULL);
	i = -1;
	k = 0;
	while (++i < ft_nword(s, c))
	{
		j = 0;
		if (!(buf[i] = ft_strnew(ft_lenword(s + k, c) + 1)))
			return (ft_delstrsplit(&buf, i));
		while (s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			buf[i][j++] = s[k++];
		buf[i][j] = '\0';
	}
	buf[i] = NULL;
	return (buf);
}
