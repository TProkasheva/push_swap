/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:13:19 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:13:22 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_arr(int **sor, int size)
{
	int i;
	int j;
	int buf;
	int *sort;

	sort = *sor;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sort[i] > sort[j])
			{
				buf = sort[i];
				sort[i] = sort[j];
				sort[j] = buf;
			}
			j++;
		}
		i++;
	}
}

t_stack		*atostack(int *arg, int size)
{
	t_stack	*a;
	t_stack	*head;
	int		i;

	validate_arr(arg, size);
	a = malloc(sizeof(t_stack));
	a->num = arg[0];
	head = a;
	i = 1;
	while (size > i)
	{
		a->next = malloc(sizeof(t_stack));
		a = a->next;
		a->num = arg[i];
		i++;
		a->next = NULL;
	}
	a->next = NULL;
	ft_memdel((void **)&arg);
	return (head);
}

void		validate_arr(int *arg, int size)
{
	int i;
	int j;

	if (!size)
		ft_exit();
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arg[i] == arg[j] && j != i)
			{
				ft_memdel((void **)&arg);
				ft_exit();
			}
			j++;
		}
		i++;
	}
}

int			*readtoarr(char **argv, int size)
{
	int i;
	int *arg;

	arg = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (argv[i])
	{
		arg[i] = ft_atoi(argv[i]);
		ft_strdel(&argv[i]);
		i++;
	}
	free(argv);
	return (arg);
}

t_stack		*fillingstack(char **av, t_flags *flags)
{
	char	**argv;
	int		*arg;
	int		i;

	get_flags(av, flags);
	argv = read_to_arr(av, flags);
	i = 0;
	while (argv[i])
		i++;
	arg = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (argv[++i])
	{
		if (!validate_str(argv[i]))
		{
			while (argv[i])
				ft_strdel(&argv[i++]);
			free(argv);
			ft_exit();
		}
		arg[i] = ft_atoi(argv[i]);
		ft_memdel((void**)&argv[i]);
	}
	free(argv);
	return (atostack(arg, i));
}
