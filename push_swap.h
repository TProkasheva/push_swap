/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:14:24 by nslughor          #+#    #+#             */
/*   Updated: 2020/09/09 17:14:25 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define RED "\x1B[31m"
# define WHT "\x1B[39m"
# include "libft/libft.h"

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_flags
{
	char				v;
	char				c;
	char				stack;
	int					flag;
	t_stack				**b;
	t_stack				**a;
	int					*sort;
}						t_flags;

void					ft_atoi_check(const char *str);
t_stack					*atostack(int *arg, int size);
void					swap(t_stack **head);
void					ft_sswap(t_stack **a, t_stack **b);
void					ft_push(t_stack **from, t_stack **to);
void					ft_rotate(t_stack **rotatable);
void					ft_rrotate(t_stack **a, t_stack **b);
void					rrotateab(t_stack **rrotatable);
void					rrrotate(t_stack **a, t_stack **b);
int						check(t_stack *a);
int						check_reversed(t_stack *a);
t_stack					*fillingstack(char **argv, t_flags *flags);
void					ft_exit(void);
void					validate_arr(int *arg, int size);
int						validate_string(char *str);
t_stack					*find_biggest(t_stack *b);
t_stack					*find_smallest(t_stack *a);
int						get_ptr_pos(t_stack *a, t_stack *num);
void					move_num_up(t_stack **a, t_stack *num,
						int size, t_flags *flags);
void					push_swap(t_stack *a, t_stack *b,
						int size, t_flags *flags);
void					sort_arr(int **arg, int size);
int						*readtoarr(char **av, int size);
int						count_operations(t_stack *a, int num, int size);
t_stack					*find_num(t_stack *a, int number);
t_stack					*find_min_ops(t_stack *a, int *sort,
						int max, int start);
int						get_size(t_stack *a);
void					free_stack(t_stack **a);
void					free_exec(char **str, t_stack *a, t_stack *b);
t_stack					*stackcpy(t_stack *a);
char					**read_to_arr(char **av, t_flags *flags);
int						validate_str(char *str);
void					less_5(t_stack **a, t_stack **b,
						int size, t_flags *flags);
void					get_flags(char **av, t_flags *flags);
void					write_stacks(t_stack *a, t_stack *b,
						t_flags *flags, int op);
int						ft_numlen(int n);
void					write_bonus(t_stack *a, t_stack *b,
						int op, t_flags *flags);

#endif
