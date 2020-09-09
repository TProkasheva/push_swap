/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:14:53 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:55 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_ptr_pos(t_stack *a, t_stack *num)
{
	int counter;

	counter = 0;
	while (a != num)
	{
		a = a->next;
		counter++;
	}
	return (counter);
}

static int		count_ops2(t_stack **cpy, t_stack *numb, int ops, int size)
{
	if (get_ptr_pos(*cpy, numb) > size / 2)
	{
		while (*cpy != numb)
		{
			if ((*cpy)->next == numb)
				swap(cpy);
			else
				rrotateab(cpy);
			ops++;
		}
	}
	else
	{
		while (*cpy != numb)
		{
			if ((*cpy)->next == numb)
				swap(cpy);
			else
				rrotateab(cpy);
			ops++;
		}
	}
	return (ops);
}

int				count_operations(t_stack *a, int num, int size)
{
	int		ops;
	t_stack	*cpy;
	t_stack	*numb;

	ops = 0;
	cpy = stackcpy(a);
	numb = find_num(cpy, num);
	if (numb == NULL)
	{
		free_stack(&cpy);
		return (-1);
	}
	ops += count_ops2(&cpy, numb, ops, size);
	free_stack(&cpy);
	return (ops);
}

static void		rrab_up(t_stack **a, t_stack *num, t_flags *flags)
{
	while (*a != num)
	{
		if ((*a)->next == num)
		{
			swap(a);
			write_stacks(*a, *flags->b, flags, flags->stack == 'a' ? 1 : 2);
		}
		else
		{
			rrotateab(a);
			write_stacks(*a, *flags->b, flags, flags->stack == 'a' ? 9 : 10);
		}
	}
}

void			move_num_up(t_stack **a, t_stack *num, int size, t_flags *flags)
{
	if (!(*a)->next)
		return ;
	if (get_ptr_pos(*a, num) > size / 2)
		rrab_up(a, num, flags);
	else
	{
		while (*a != num)
		{
			if ((*a)->next == num)
			{
				swap(a);
				write_stacks(*flags->a, *flags->b, flags\
				, flags->stack == 'a' ? 1 : 2);
			}
			else
			{
				ft_rotate(a);
				write_stacks(*flags->a, *flags->b, flags\
				, flags->stack == 'a' ? 6 : 7);
			}
		}
	}
}
