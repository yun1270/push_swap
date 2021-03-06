/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:43:21 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 15:43:23 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_021(t_stack *s1, t_stack *s2)
{
	if (s1->size == 3)
	{
		ft_command_1(1, "rra", s1, s2);
		ft_command_1(1, "sa", s1, s2);
	}
	else
	{
		ft_command_1(1, "pb", s1, s2);
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}

void	simple_102(t_stack *s1, t_stack *s2)
{
	ft_command_1(1, "sa", s1, s2);
}

void	simple_120(t_stack *s1, t_stack *s2)
{
	if (s1->size == 3)
		ft_command_1(1, "rra", s1, s2);
	else
	{
		ft_command_1(1, "pb", s1, s2);
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "sa", s1, s2);
	}
}

void	simple_210(t_stack *s1, t_stack *s2)
{
	if (s1->size == 3)
	{
		ft_command_1(1, "ra", s1, s2);
		ft_command_1(1, "sa", s1, s2);
	}
	else
	{
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pb", s1, s2);
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
		ft_command_1(1, "sa", s1, s2);
	}
}

void	simple_201(t_stack *s1, t_stack *s2)
{
	if (s1->size == 3)
		ft_command_1(1, "ra", s1, s2);
	else
	{
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pb", s1, s2);
		ft_command_1(1, "sa", s1, s2);
		ft_command_1(1, "pa", s1, s2);
	}
}
