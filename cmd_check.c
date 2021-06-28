/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:37:49 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 20:54:12 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_command(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

int			ft_command_1(int n, char *str, t_stack *s1, t_stack *s2)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(n, s1, s2);
	else if (ft_strcmp(str, "sb") == 0)
		swap(n, s2, s1);
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(n, s2, s1);
		swap(n, s1, s2);
	}
	else if (ft_strcmp(str, "ra") == 0)
		rotate(n, s1, s2);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(n, s2, s1);
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate(n, s1, s2);
		rotate(n, s2, s1);
	}
	else
		return (ft_command_2(n, str, s1, s2));
	if (n == 1)
		print_command(str);
	return (0);
}

int			ft_command_2(int n, char *str, t_stack *s1, t_stack *s2)
{
	if (ft_strcmp(str, "pa") == 0)
		push_to(s2, s1);
	else if (ft_strcmp(str, "pb") == 0)
		push_to(s1, s2);
	else if (ft_strcmp(str, "rra") == 0)
		rev_rotate(n, s1, s2);
	else if (ft_strcmp(str, "rrb") == 0)
		rev_rotate(n, s2, s1);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		rev_rotate(n, s1, s2);
		rev_rotate(n, s2, s1);
	}
	else
		return (1);
	if (n == 1)
		print_command(str);
	return (0);
}
