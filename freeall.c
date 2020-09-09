/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:13:51 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:13:52 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack *buf;

	while (*a)
	{
		buf = (*a)->next;
		free(*a);
		*a = buf;
	}
	*a = NULL;
}

void	free_exec(char **str, t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a)
		free_stack(&a);
	if (b)
		free_stack(&b);
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
}
