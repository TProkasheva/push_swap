/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:14:39 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:40 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack *buf;

	if (!(*from))
		return ;
	buf = (*from)->next;
	(*from)->next = (*to);
	(*to) = (*from);
	(*from) = buf;
}

void	ft_rotate(t_stack **rotatable)
{
	t_stack *head;

	if ((*rotatable) && (*rotatable)->next)
	{
		head = (*rotatable);
		while ((*rotatable)->next)
			(*rotatable) = (*rotatable)->next;
		(*rotatable)->next = head;
		(*rotatable) = head->next;
		head->next = NULL;
	}
}

void	ft_rrotate(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	rrotateab(t_stack **rrotatable)
{
	t_stack *end;

	if ((*rrotatable) && (*rrotatable)->next)
	{
		end = (*rrotatable);
		while (end->next->next)
			end = end->next;
		end->next->next = (*rrotatable);
		(*rrotatable) = end->next;
		end->next = NULL;
	}
}

void	rrrotate(t_stack **a, t_stack **b)
{
	rrotateab(a);
	rrotateab(b);
}
