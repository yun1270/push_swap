/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:46:58 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 15:53:30 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_ab(int ra, int rb, t_stack *s1, t_stack *s2)
{
	int	rr_cnt;
	int r_cnt;

	if (ra < rb)
	{
		rr_cnt = ra;
		r_cnt = rb - ra;
		while (r_cnt--)
			ft_command_1(1, "rrb", s1, s2);
	}
	else
	{
		rr_cnt = rb;
		r_cnt = ra - rb;
		while (r_cnt--)
			ft_command_1(1, "rra", s1, s2);
	}
	while (rr_cnt--)
		ft_command_1(1, "rrr", s1, s2);
}

void	move_a_to_b(int n, int *pivot, t_stack *s1, t_stack *s2)
{
	int	ra;
	int	rb;
	int	pb;

	ra = 0;
	rb = 0;
	pb = 0;
	while (n--)
	{
		if (s1->head->num >= pivot[1] && ++ra)
			ft_command_1(1, "ra", s1, s2);
		else
		{
			ft_command_1(1, "pb", s1, s2);
			pb++;
			if (s2->head->num >= pivot[0] && ++rb)
				ft_command_1(1, "rb", s1, s2);
		}
	}
	rrr_ab(ra, rb, s1, s2);
	a_to_b(ra, s1, s2);
	b_to_a(rb, s1, s2);
	b_to_a(pb - rb, s1, s2);
}

void	move_b_to_a(int n, int *pivot, t_stack *s1, t_stack *s2)
{
	int	ra;
	int	rb;
	int	pa;

	ra = 0;
	rb = 0;
	pa = 0;
	while (n--)
	{
		if (s2->head->num < pivot[0] && ++rb)
			ft_command_1(1, "rb", s1, s2);
		else
		{
			ft_command_1(1, "pa", s1, s2);
			pa++;
			if (s1->head->num < pivot[1] && ++ra)
				ft_command_1(1, "ra", s1, s2);
		}
	}
	a_to_b(pa - ra, s1, s2);
	rrr_ab(ra, rb, s1, s2);
	a_to_b(ra, s1, s2);
	b_to_a(rb, s1, s2);
}

void	a_to_b(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];

	if (n <= 3)
	{
		if (n == 2 && s1->head->num > s1->head->link->num)
			ft_command_1(1, "sa", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'a');
		return ;
	}
	pick_2_pivot(s1, pivot, n);
	move_a_to_b(n, pivot, s1, s2);
}

void	b_to_a(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];

	if (n <= 3)
	{
		if (n == 2 && s2->head->num < s2->head->link->num)
			ft_command_1(1, "sb", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'b');
		if (!(n == 3 && s2->size != 3))
			while (n--)
				ft_command_1(1, "pa", s1, s2);
		return ;
	}
	pick_2_pivot(s2, pivot, n);
	move_b_to_a(n, pivot, s1, s2);
}
