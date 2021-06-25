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
    char    *line;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	set_stack(ac, av, a, b);
	check_buf(a);

	int i;
    while ((i = get_next_line(0, &line)))
    {
		if (i == 0 && !(ft_strstr(line, "\n")))
			break ;
        if (ft_command_1(0, line, a, b))
            error();
        ft_strdel(&line);
    }
	
	if (stack_is_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	exit(0);
}
