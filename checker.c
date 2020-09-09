/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:13:30 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:13:31 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_1(char **list, t_stack **a, t_stack **b, int i)
{
	if (ft_strequ(list[i], "sa"))
		swap(a);
	else if (ft_strequ(list[i], "sb"))
		swap(b);
	else if (ft_strequ(list[i], "ss"))
		ft_sswap(a, b);
	else if (ft_strequ(list[i], "pa"))
		ft_push(b, a);
	else if (ft_strequ(list[i], "pb"))
		ft_push(a, b);
	else if (ft_strequ(list[i], "ra"))
		ft_rotate(a);
	else if (ft_strequ(list[i], "rb"))
		ft_rotate(b);
	else if (ft_strequ(list[i], "rr"))
		ft_rrotate(a, b);
	else if (ft_strequ(list[i], "rra"))
		rrotateab(a);
	else if (ft_strequ(list[i], "rrb"))
		rrotateab(b);
	else if (ft_strequ(list[i], "rrr"))
		rrrotate(b, a);
	else
		return (0);
	return (1);
}

int			exec(char *str, t_stack *a, t_stack *b)
{
	char	**list;
	int		i;

	i = 0;
	list = ft_strsplit(str, '\n');
	while (list[i])
	{
		if (!exec_1(list, &a, &b, i))
		{
			free_exec(list, a, b);
			free(list);
			ft_exit();
		}
		i++;
	}
	i = (check(a) && !b) ? 1 : 0;
	free_exec(list, a, b);
	free(list);
	return (i);
}

int			main(int ac, char **av)
{
	char	*line;
	char	*str;
	t_stack	*a;
	t_flags	flags;

	if (ac < 2)
		return (0);
	a = fillingstack(av, &flags);
	str = ft_strnew(0);
	while (get_next_line(1, &line) > 0)
	{
		ft_swap((void **)&str, ft_strjoin(str, line));
		ft_swap((void **)&str, ft_strjoin(str, "\n"));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (exec(str, a, NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_strdel(&str);
	return (0);
}
