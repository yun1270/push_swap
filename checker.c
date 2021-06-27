#include "push_swap.h"

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
