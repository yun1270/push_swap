#include "push_swap.h"

static void	print_command(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void		ft_command_1(char *str, t_stack *s1, t_stack *s2)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(s1);
	else if (ft_strcmp(str, "sb") == 0)
		swap(s2);
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(s2);
		swap(s1);
	}
	else if (ft_strcmp(str, "ra") == 0)
		rotate(s1);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(s2);
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate(s1);
		rotate(s2);
	}
	else
	{
		ft_command_2(str, s1, s2);
		return;
	}
	print_command(str);
}

void		ft_command_2(char *str, t_stack *s1, t_stack *s2)
{
	if (ft_strcmp(str, "pa") == 0)
		push_to(s2, s1);
	else if (ft_strcmp(str, "pb") == 0)
		push_to(s1, s2);
	else if (ft_strcmp(str, "rra") == 0)
		rev_rotate(s1);
	else if (ft_strcmp(str, "rrb") == 0)
		rev_rotate(s2);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		rev_rotate(s1);
		rev_rotate(s2);
	}
	else
		error();
	print_command(str);
}
