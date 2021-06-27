#include "push_swap.h"

int			main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	set_stack(ac, av, a, b);

	if (a->size == 1)
		error();
	check_buf(a);
	if (a->size == 2)
	{
		if (a->head->num > a->head->link->num)
			ft_command_1(1, "sa", a, b);
	}
	else if (a->size == 3)
		simple_sort(a, b, 'a');
	else if (a->size <= 6)
		sort_small(a->size, a, b);
	else
		A_to_B(a->size, a, b);
	// print_list(a, b);
	exit(0);
}
