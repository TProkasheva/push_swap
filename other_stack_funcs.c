/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_stack_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:14:12 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:12 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(t_stack *a)
{
	if (!a)
		return (0);
	else if (a && !a->next)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int		get_size(t_stack *a)
{
	int counter;

	counter = 0;
	while (a)
	{
		a = a->next;
		counter++;
	}
	return (counter);
}

int		check_reversed(t_stack *a)
{
	while (a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*find_biggest(t_stack *b)
{
	t_stack *biggest;

	biggest = b;
	while (b)
	{
		if (b->num > biggest->num)
			biggest = b;
		b = b->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *a)
{
	t_stack *smallest;

	smallest = a;
	while (a)
	{
		if (a->num < smallest->num)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}
