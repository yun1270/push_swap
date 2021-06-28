#include "push_swap.h"

void print_list(t_stack *s1, t_stack *s2)
{
	t_node *n;

	printf("A => ");
	n = s1->head;
	while (n)
	{
		printf("%d | ",n->num);
		n = n->link;
	}
	printf("\n B => ");

	n = s2->head;
	while (n)
	{
		printf("%d | ",n->num);
		n = n->link;
	}
	printf("\n ");
}

void			del_stack(t_stack *s1, t_stack *s2)
{
	t_node		*n;
	t_node		*del;

	n = s1->head;
	while (n)
	{
		del = n;
		n = n->link;
		free(del);
	}
	free(s1);
	n = s2->head;
	while (n)
	{
		del = n;
		n = n->link;
		free(del);
	}
	free(s2);
}

void			error(t_stack *s1, t_stack *s2)
{
	ft_putstr_fd("Error\n", 2);
	del_stack(s1, s2);
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

void			check_buf(t_stack *s1, t_stack *s2)
{
	int			i;
	int			*buf;

	buf = malloc(sizeof(int) * (s1->size + 1));
	set_buf(buf, s1, s1->size);
	sort_buf(buf, s1->size);
	i = 0;
	while(++i < s1->size)
	{
		if(buf[i] == buf[i - 1])
			error(s1, s2);
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
        error(s1, s2);
    if (ac == 2 && ft_strchr(av[1], ' '))
        av = ft_split(av[1], ' ');
	i = ft_avlen(av);
	while (--i > 0)
	{
		if (check_av(av[i]) == 0)
			error(s1, s2);
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			error(s1, s2);
		push(num, s1);
	}
}
