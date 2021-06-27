#include "push_swap.h"

int				stack_is_sorted(t_stack *s1)
{
	t_node		*s;

	s = s1->head;
	while (s->link)
	{
		if (s->num >= s->link->num)
			return (1);
		s = s->link;
	}
	return (0);
}

int			main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
    char    *line;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	set_stack(ac, av, a, b);
	if (a->size == 1)
		error(a, b);
	check_buf(a, b);
    while ((i = get_next_line(0, &line)))
    {
		if (i == 0 && !(ft_strstr(line, "\n")))
			break ;
        if (ft_command_1(0, line, a, b))
            error(a, b);
        ft_strdel(&line);
    }
	if (stack_is_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	exit(0);
}
