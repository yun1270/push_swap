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
	printf("==========================================\n");
}

int			main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	set_stack(ac, av, a, b);
	print_list(a, b);

	if (a->size == 1)
		;
	else if (a->size == 2)
	{
		if (a->head->num > a->head->link->num)
			ft_command_1("sa", a, b);
	}
	else if (a->size <= 3)
		simple_sort(a, b, 'a');
	else if (a->size <= 6)
		sort_small(a->size, a, b);
	else
		A_to_B(a->size, a, b);
	print_list(a, b);
	exit(0);
}
