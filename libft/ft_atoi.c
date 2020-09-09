/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:24:54 by nslughor          #+#    #+#             */
/*   Updated: 2019/10/23 13:01:54 by cimogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int				s;
	long long int	sum;
	int				i;

	sum = 0;
	s = 1;
	i = 0;
	while ((ptr[i] == '\n') || (ptr[i] == '\t') || (ptr[i] == '\v') ||
	(ptr[i] == '\f') || (ptr[i] == '\r') || (ptr[i] == ' '))
		i++;
	if ((ptr[i] == '+') || (ptr[i] == '-'))
		if (ptr[i++] == '-')
			s = -1;
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		sum = sum * 10 + (ptr[i] - '0');
		if (sum < 0 && s == -1)
			return (0);
		if (sum < 0 && s == 1)
			return (-1);
		i++;
	}
	return ((int)(s * sum));
}
