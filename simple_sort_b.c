
#include "push_swap.h"

void    b_simple_012(t_stack *s1, t_stack *s2)
{
    if (s2->size == 3)
    {
        ft_command_1("sb", s1, s2);
        ft_command_1("rrb", s1, s2);
    }
    else
    {
		ft_command_1("sb", s1, s2);
		ft_command_1("pa", s1, s2);
		ft_command_1("sb", s1, s2);
		ft_command_1("pb", s1, s2);
		ft_command_1("sb", s1, s2);
    }
}

void    b_simple_021(t_stack *s1, t_stack *s2)
{
    if (s2->size == 3)
    	ft_command_1("rb", s1, s2);
	else
	{
		ft_command_1("sb", s1, s2);
		ft_command_1("pa", s1, s2);
		ft_command_1("sb", s1, s2);
		ft_command_1("pb", s1, s2);
	}
}

void    b_simple_102(t_stack *s1, t_stack *s2)
{
    if (s2->size == 3)
        ft_command_1("rrb", s1, s2);
    else
    {
        ft_command_1("pa", s1, s2);
        ft_command_1("sb", s1, s2);
        ft_command_1("pb", s1, s2);
        ft_command_1("sb", s1, s2);
    }
}

void    b_simple_120(t_stack *s1, t_stack *s2)
{
    ft_command_1("sb", s1, s2);
}

void    b_simple_201(t_stack *s1, t_stack *s2)
{
	if (s2->size == 3)
    {
		ft_command_1("rrb", s1, s2);
    	ft_command_1("rrb", s1, s2);
	}
	else
	{
		ft_command_1("pa", s1, s2);
		ft_command_1("sb", s1, s2);
		ft_command_1("pb", s1, s2);
	}
}
