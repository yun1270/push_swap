/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:12:36 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 20:04:19 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct		s_node
{
	int				num;
	struct s_node	*link;
}					t_node;

typedef struct		s_stack
{
	int				size;
	struct s_node	*head;
}					t_stack;

void				b_to_a(int n, t_stack *s1, t_stack *s2);
void				a_to_b(int n, t_stack *s1, t_stack *s2);
int					stack_is_sorted(t_stack *s1);
void				del_stack(t_stack *s1, t_stack *s2);
void				set_stack(int ac, char **av, t_stack *s1, t_stack *s2);
void				error(t_stack *s1, t_stack *s2);
void				check_buf(t_stack *s1, t_stack *s2);
int					check_av(char *str);
void				sort_buf(int *buf, int size);
void				pick_2_pivot(t_stack *s, int *pivot, int n);
void				pick_1_pivot(t_stack *s, int *pivot, int n);
void				set_buf(int *buf, t_stack *s, int n);
void				push(int num, t_stack *s);
void				push_to(t_stack *s1, t_stack *s2);
void				swap(int n, t_stack *s, t_stack *s2);
void				rotate(int n, t_stack *s, t_stack *s2);
void				rev_rotate(int n, t_stack *s, t_stack *s2);
int					ft_command_1(int n, char *str, t_stack *s1, t_stack *s2);
int					ft_command_2(int n, char *str, t_stack *s1, t_stack *s2);
void				sort_small(int n, t_stack *s1, t_stack *s2);
void				simple_sort(t_stack *s1, t_stack *s2, char st);
void				simple_021(t_stack *s1, t_stack *s2);
void				simple_102(t_stack *s1, t_stack *s2);
void				simple_120(t_stack *s1, t_stack *s2);
void				simple_210(t_stack *s1, t_stack *s2);
void				simple_201(t_stack *s1, t_stack *s2);
void				b_simple_012(t_stack *s1, t_stack *s2);
void				b_simple_021(t_stack *s1, t_stack *s2);
void				b_simple_102(t_stack *s1, t_stack *s2);
void				b_simple_120(t_stack *s1, t_stack *s2);
void				b_simple_201(t_stack *s1, t_stack *s2);

#endif
