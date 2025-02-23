/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:14:19 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:20 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_b(t_stack **a, t_stack **b, t_flags *flags)
{
	while (*b)
	{
		move_num_up(b, find_biggest(*b), get_size(*b), flags);
		ft_push(b, a);
		write_stacks(*flags->a, *flags->b, flags, 4);
	}
}

static void	less_100(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 5;
	counter = 0;
	while (*a)
	{
		flags->stack = 'a';
		number = find_min_ops(*a, flags->sort, max, start);
		move_num_up(a, number, get_size(*a), flags);
		counter++;
		if (counter == max)
		{
			start = start + size / 5 > size ? size : start + size / 5;
			max = max + size / 5 > size ? size : max + size / 5;
		}
		ft_push(a, b);
		write_stacks(*a, *b, flags, 5);
	}
	flags->stack = 'b';
	clear_b(a, b, flags);
}

static void	more(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 11;
	counter = 0;
	while (*a)
	{
		flags->stack = 'a';
		number = find_min_ops(*a, flags->sort, max, start);
		move_num_up(a, number, get_size(*a), flags);
		counter++;
		if (counter == max)
		{
			start = start + size / 11 > size ? size : start + size / 11;
			max = max + size / 11 > size ? size : max + size / 11;
		}
		ft_push(a, b);
		write_stacks(*a, *b, flags, 5);
	}
	flags->stack = 'b';
	clear_b(a, b, flags);
}

void		push_swap(t_stack *a, t_stack *b, int size, t_flags *flags)
{
	flags->b = &b;
	flags->a = &a;
	if (size <= 5 || check(a))
		less_5(&a, &b, size, flags);
	else if (size <= 101)
		less_100(&a, &b, size, flags);
	else
		more(&a, &b, size, flags);
	free_stack(&a);
	a = NULL;
}

int			main(int ac, char **av)
{
	t_stack	*a;
	int		size;
	t_flags	flags;

	if (ac < 2)
		return (0);
	flags.stack = 'a';
	a = fillingstack(av, &flags);
	size = get_size(a);
	flags.sort = readtoarr(read_to_arr(av, &flags), size);
	sort_arr(&flags.sort, size);
	push_swap(a, NULL, size, &flags);
	ft_memdel((void **)&flags.sort);
	return (0);
}
