#include "push_swap.h"

void print_list(t_stack *a, t_stack *b)
{
	int i;
	t_node *temp = a->head;
	t_node *tmp = b->head;

	printf("node_CHECK ==========================================\n");
	printf("A_size = %d\n", a->size);
	for (int j = 0; j < a->size; j++)
	{
		i = 1;
		printf("A :: %d", temp->num);
		while (i++ <= temp->num)
			printf("_");
		temp = temp->link;
		printf("\n");
	}
	printf("\n");
	printf("B_size = %d\n", b->size);
	for (int j = 0; j < b->size; j++)
	{
		i = 1;
		printf("B :: %d", tmp->num);
		while (i++ <= tmp->num)
			printf("_");
		tmp = tmp->link;
		printf("\n");
	}
}

void rrr_ab(int ra, int rb, t_stack *s1, t_stack *s2)
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

void	A_to_B(int n, t_stack *s1, t_stack *s2)
{
	printf("A_to_B start\n");
	print_list(s1, s2);
	int	pivot[2];
	int	ra;
	int	rb;
	int	pb;

	ra = 0;
	rb = 0;
	pb = 0;
	if (n <= 3)
	{
		simple_sort(s1, s2);
		return;
	}
	pick_2_pivot(s1, pivot);
	while (n--)
	{
		if (s1->head->num >= pivot[1])
		{
			ft_command_1("ra", s1, s2);
			ra++;
		}
		else
		{
			ft_command_1("pb", s1, s2);
			pb++;
			if (s2->head->num >= pivot[0])
			{
				ft_command_1("rb", s1, s2);
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
	printf("B_to_A start\n");
	print_list(s1, s2);
	int	pivot[2];
	int	ra;
	int	rb;
	int	pa;

	ra = 0;
	rb = 0;
	pa = 0;
	if (n <= 3)
	{
		simple_sort_b(s1, s2, n);
		while (n--)
			ft_command_1("pa", s1, s2);
		return ;
	}
	pick_2_pivot(s2, pivot);
	while (n--)
	{
		if (s2->head->num <= pivot[0])
		{
			ft_command_1("rb", s1, s2);
			rb++;
		}
		else
		{
			ft_command_1("pa", s1, s2);
			pa++;
			if (s1->head->num <= pivot[1])
			{
				ft_command_1("ra", s1, s2);
				ra++;
			}
		}
	}
	A_to_B(pa - ra, s1, s2);
	rrr_ab(ra, rb, s1, s2);
	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
}

int		check_av(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9'))
		return (0);
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int			main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;

	int i;
	long long num;

	i = 0;
	if (ac == 1)
        return (0);
    if (ac == 2 && ft_strchr(av[1], ' '))
        av = ft_split(av[1], ' ');
	while (++i < ac)
	{
		if (check_av(av[i]) == 0)
			error();
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			error();
		push(num, a);
	}
	print_list(a, b);

	if (a->size == 3)
		simple_sort(a, b);
	

	// if (a->size <= 6)
	// 	small_A_to_B(a->size, a, b);
	else
		A_to_B(a->size, a, b);
	// simple_sort(a,b);
	print_list(a, b);
}
