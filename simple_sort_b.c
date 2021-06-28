/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:43:33 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 15:45:10 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_simple_012(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
	{
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "rrb", s1, s2);
	}
	else
	{
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "rb", s1, s2);
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "rrb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}

void	b_simple_021(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
		ft_command_1(1, "rb", s1, s2);
	else
	{
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}

void	b_simple_102(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
		ft_command_1(1, "rrb", s1, s2);
	else
	{
		ft_command_1(1, "rb", s1, s2);
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "rrb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}

void	b_simple_120(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
		ft_command_1(1, "sb", s1, s2);
	else
	{
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}

void	b_simple_201(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
	{
		ft_command_1(1, "rrb", s1, s2);
		ft_command_1(1, "sb", s1, s2);
	}
	else
	{
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "sb", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}
