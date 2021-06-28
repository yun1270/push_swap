/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:37:58 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 20:54:15 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	set_stack(ac, av, a, b);
	check_buf(a, b);
	if (stack_is_sorted(a) == 0 || a->size == 1)
	{
		del_stack(a, b);
		exit(0);
	}
	if (a->size == 2)
	{
		if (a->head->num > a->head->link->num)
			ft_command_1(1, "sa", a, b);
	}
	else if (a->size == 3)
		simple_sort(a, b, 'a');
	else if (a->size <= 6)
		sort_small(a->size, a, b);
	else
		a_to_b(a->size, a, b);
	del_stack(a, b);
	exit(0);
}
