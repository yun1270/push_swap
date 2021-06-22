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
			ft_command_1("rrb", s1, s2);
	}
	else
	{
		rr_cnt = rb;
		r_cnt = ra - rb;
		while (r_cnt--)
			ft_command_1("rra", s1, s2);
	}
	while (rr_cnt--)
		ft_command_1("rrr", s1, s2);

}

int		*move_a_to_b(int n, int *pivot, t_stack *s1, t_stack *s2)
{
	int	*cmd_n;

	cmd_n = NULL;
	cmd_n[0] = 0;
	cmd_n[1] = 0;
	cmd_n[2] = 0;
	while (n--)
	{
		if (s1->head->num >= pivot[1])
		{
			ft_command_1("ra", s1, s2);
			cmd_n[0]++;
		}
		else
		{
			ft_command_1("pb", s1, s2);
			cmd_n[1]++;
			if (s2->head->num >= pivot[0])
			{
				ft_command_1("rb", s1, s2);
				cmd_n[2]++;
			}
		}
	}
	return (cmd_n);
}

int		*move_b_to_a(int n, int *pivot, t_stack *s1, t_stack *s2)
{
	int	*cmd_n;

	cmd_n = NULL;
	cmd_n[0] = 0;
	cmd_n[1] = 0;
	cmd_n[2] = 0;
	while (n--)
	{
		if (s2->head->num <= pivot[0])
		{
			ft_command_1("rb", s1, s2);
			cmd_n[0]++;
		}
		else
		{
			ft_command_1("pa", s1, s2);
			cmd_n[1]++;
			if (s1->head->num <= pivot[1])
			{
				ft_command_1("ra", s1, s2);
				cmd_n[2]++;
			}
		}
	}
	return (cmd_n);
}

void	A_to_B(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];
	int *cmd_n;
	int	ra;
	int	rb;
	int	pb;

	if (n <= 3)
	{
		if (n == 2 && s1->head->num > s1->head->link->num)
			ft_command_1("sa", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'a');
		return ;
	}
	pick_2_pivot(s1, pivot);
	cmd_n = move_a_to_b(n, pivot, s1, s2);
	ra = cmd_n[0];
	pb = cmd_n[1];
	rb = cmd_n[2];
	rrr_ab(ra, rb, s1, s2);
	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
	B_to_A(pb - rb, s1, s2);
}

void	B_to_A(int n, t_stack *s1, t_stack *s2)
{
	int	pivot[2];
	int *cmd_n;
	int	ra;
	int	rb;
	int	pa;

	if (n <= 3)
	{
		if (n == 2 && s2->head->num < s2->head->link->num)
			ft_command_1("sb", s1, s2);
		else if (n == 3)
			simple_sort(s1, s2, 'b');
		while (n--)
			ft_command_1("pa", s1, s2);
		return ;
	}
	pick_2_pivot(s2, pivot);
	cmd_n = move_b_to_a(n, pivot, s1, s2);
	rb = cmd_n[0];
	pa = cmd_n[1];
	ra = cmd_n[2];
	A_to_B(pa - ra, s1, s2);
	rrr_ab(ra, rb, s1, s2);
	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
}
