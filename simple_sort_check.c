#include "push_swap.h"

static void	check_012(int *s, t_stack *s1, t_stack *s2)
{
	char	size[4];
	int		i;

	i = -1;
	while (++i < 3)
		size[i] = '0' + s[i];
	size[i] = '\0';
	if (!ft_strcmp(size, "132"))
		simple_021(s1, s2);
	else if (!ft_strcmp(size, "213"))
		simple_102(s1, s2);
	else if (!ft_strcmp(size, "231"))
		simple_120(s1, s2);
	else if (!ft_strcmp(size, "321"))
		simple_210(s1, s2);
	else if (!ft_strcmp(size, "312"))
		simple_201(s1, s2);
}

static void	check_210(int *s, t_stack *s1, t_stack *s2)
{
	char	size[4];
	int		i;

	i = -1;
	while (++i < 3)
		size[i] = '0' + s[i];
	size[i] = '\0';
	if (!ft_strcmp(size, "123"))
		b_simple_012(s1, s2);
	else if (!ft_strcmp(size, "132"))
		b_simple_021(s1, s2);
	else if (!ft_strcmp(size, "213"))
		b_simple_102(s1, s2);
	else if (!ft_strcmp(size, "231"))
		b_simple_120(s1, s2);
	else if (!ft_strcmp(size, "312"))
		b_simple_201(s1, s2);
	// print_list(s1,s2);
	
}

static void	set_012(int *buf, char s, t_stack *s1, t_stack *s2)
{
	int		size[3];
	int		i;
	int		j;

	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	i = -1;
	while (++i < 3)
	{
		j = i - 1;
		while (++j < 3)
		{
			if (buf[i] > buf[j])
				size[i]++;
			else
				size[j]++;
		}
	}
	if (s == 'a')
		check_012(size, s1, s2);
	else if (s == 'b')
		check_210(size, s1, s2);
}

void		sort_small(int n, t_stack *s1, t_stack *s2)
{
	int		pivot[1];
	int		pb;

	pb = 0;
	pick_1_pivot(s1, pivot);
	while (n--)
	{
		if (s1->head->num >= pivot[0])
			ft_command_1("ra", s1, s2);
		else
		{
			ft_command_1("pb", s1, s2);
			pb++;
		}
	}
	simple_sort(s1, s2);
	simple_sort_b(s1, s2);
	while (pb--)
		ft_command_1("pa", s1, s2);
}

void		simple_sort(t_stack *s1, t_stack *s2)
{
	int		buf[4];

	// printf("============simple_sort start %d head->[ %d ]\n", s1->size, s1->head->num);
	if (s1->size == 3)
	{
		set_buf(buf, s1);
		set_012(buf, 'a', s1, s2);
	}
}

void		simple_sort_b(t_stack *s1, t_stack *s2)
{
	int		buf[4];

	// printf("============simple_sort_b start %d head->[ %d ]\n", s2->size, s2->head->num);
	if (s2->size == 3)
	{
		set_buf(buf, s2);
		set_012(buf, 'b', s1, s2);
	}
}