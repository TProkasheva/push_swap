/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:15:13 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:15:17 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack *buf;

	if ((*head) && (*head)->next)
	{
		buf = (*head)->next;
		(*head)->next = (*head)->next->next;
		buf->next = (*head);
		(*head) = buf;
	}
}

void	ft_sswap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
