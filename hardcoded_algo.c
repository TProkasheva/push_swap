/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:13:59 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:01 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size3_2(t_stack **a, t_flags *flags)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		ft_rotate(a);
		write_stacks(*a, *flags->b, flags, 6);
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rrotateab(a);
		write_stacks(*a, *flags->b, flags, 9);
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		swap(a);
		write_stacks(*a, *flags->b, flags, 1);
		ft_rotate(a);
		write_stacks(*a, *flags->b, flags, 6);
	}
}

static void	size3(t_stack **a, t_flags *flags)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num
	> (*a)->next->next->num)
	{
		swap(a);
		write_stacks(*a, *flags->b, flags, 1);
		rrotateab(a);
		write_stacks(*a, *flags->b, flags, 9);
	}
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		swap(a);
		write_stacks(*a, *flags->b, flags, 1);
	}
	size3_2(a, flags);
}

static void	size5(t_stack **a, t_stack **b, t_flags *flags)
{
	move_num_up(a, find_smallest(*a), get_size(*a), flags);
	ft_push(a, b);
	write_stacks(*a, *b, flags, 5);
	move_num_up(a, find_smallest(*a), get_size(*a), flags);
	ft_push(a, b);
	write_stacks(*a, *b, flags, 5);
	size3(a, flags);
	ft_push(b, a);
	write_stacks(*a, *b, flags, 4);
	ft_push(b, a);
	write_stacks(*a, *b, flags, 4);
}

void		less_5(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	flags->stack = 'a';
	if (size <= 1 || check(*a))
		return ;
	else if (size == 2)
	{
		if ((*a)->next->num < (*a)->num)
		{
			swap(a);
			write_stacks(*a, *b, flags, 1);
		}
	}
	else if (size == 3)
		size3(a, flags);
	else if (size == 4)
	{
		move_num_up(a, find_smallest(*a), get_size(*a), flags);
		ft_push(a, b);
		write_stacks(*a, *b, flags, 5);
		size3(a, flags);
		ft_push(b, a);
		write_stacks(*a, *b, flags, 4);
	}
	else if (size == 5)
		size5(a, b, flags);
}
