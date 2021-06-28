/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:59:28 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 20:55:42 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			del_stack(t_stack *s1, t_stack *s2)
{
	t_node		*n;
	t_node		*del;

	n = s1->head;
	while (n)
	{
		del = n;
		n = n->link;
		free(del);
	}
	free(s1);
	n = s2->head;
	while (n)
	{
		del = n;
		n = n->link;
		free(del);
	}
	free(s2);
}

void			set_stack(int ac, char **av, t_stack *s1, t_stack *s2)
{
	int			i;
	int			j;
	int			num;

	s1->size = 0;
	s2->size = 0;
	if (ac == 1)
		exit(0);
	j = 0;
	if (ac == 2 && ft_strchr(av[1], ' ') && --j)
		av = ft_split(av[1], ' ');
	i = 0;
	while (av[i])
		i++;
	while (--i > j)
	{
		if (check_av(av[i]) == 0)
			error(s1, s2);
		num = ft_atoi(av[i]);
		push(num, s1);
	}
}

int				stack_is_sorted(t_stack *s1)
{
	t_node		*s;

	s = s1->head;
	while (s->link)
	{
		if (s->num >= s->link->num)
			return (1);
		s = s->link;
	}
	return (0);
}
