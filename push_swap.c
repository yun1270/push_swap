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

void	A_to_B(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];
	int	ra;
	int	rb;
	int	pb;

	ra = 0;
	rb = 0;
	pb = 0;
	if (n <= 3)
	{
		if (n == 2 && s1->head->num > s1->head->link->num)
			ft_command_1(1, "sa", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'a');
		return ;
	}
	pick_2_pivot(s1, pivot);
	while (n--)
	{
		if (s1->head->num >= pivot[1]) 
		{
			ft_command_1(1, "ra", s1, s2);
			ra++;
		}
		else
		{
			ft_command_1(1, "pb", s1, s2);
			pb++;
			if (s2->head->num >= pivot[0])
			{
				ft_command_1(1, "rb", s1, s2);
				rb++;
			}
		}
	}
	rrr_ab(ra, rb, s1, s2);
	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
	B_to_A(pb - rb, s1, s2);
}

void	B_to_A(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];
	int	ra;
	int	rb;
	int	pa;

	ra = 0;
	rb = 0;
	pa = 0;
	if (n <= 3)
	{
		if (n == 2 && s2->head->num < s2->head->link->num)
			ft_command_1(1, "sb", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'b');
		while (n--)
			ft_command_1(1, "pa", s1, s2);
		return ;
	}
	pick_2_pivot(s2, pivot);
	while (n--)
	{
		if (s2->head->num <= pivot[0])
		{
			ft_command_1(1, "rb", s1, s2);
			rb++;
		}
		else
		{
			ft_command_1(1, "pa", s1, s2);
			pa++;
			if (s1->head->num <= pivot[1])
			{
				ft_command_1(1, "ra", s1, s2);
				ra++;
			}
		}
	}
	A_to_B(pa - ra, s1, s2);
	rrr_ab(ra, rb, s1, s2);
	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
}
