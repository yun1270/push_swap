#include "push_swap.h"

void			error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int				check_av(char *str)
{
	int			i;

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

void			check_buf(t_stack *s)
{
	int			i;
	int			*buf;

	buf = malloc(sizeof(int) * (s->size + 1));
	set_buf(buf, s, s->size);
	sort_buf(buf, s->size);
	i = 0;
	while(++i < s->size)
	{
		if(buf[i] == buf[i - 1])
			error();
	}
}

int				ft_avlen(char **av)
{
	int			i;

	i = 0;
	while(*av++)
		i++;
	return (i);
}

void			set_stack(int ac, char **av, t_stack *s1, t_stack *s2)
{
	int			i;
	long long	num;

	s1->size = 0;
	s2->size = 0;
	if (ac == 1)
        error();
    if (ac == 2 && ft_strchr(av[1], ' '))
        av = ft_split(av[1], ' ');
	i = ft_avlen(av);
	while (--i > 0)
	{
		if (check_av(av[i]) == 0)
			error();
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			error();
		push(num, s1);
	}
}

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
