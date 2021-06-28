#include "push_swap.h"

void		sort_buf(int *buf, int size)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (buf[i] < buf[j])
			{
				temp = buf[i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void		set_buf(int *buf, t_stack *s, int n)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = s->head;
	while (i < n)
	{
		buf[i++] = temp->num;
		temp = temp->link;
	}
	buf[i] = '\0';
}

void		pick_2_pivot(t_stack *s, int *pivot, int n)
{
	int		*buf;

	buf = malloc(sizeof(int) * (n + 1));
	set_buf(buf, s, n);
	sort_buf(buf, n);
	pivot[0] = buf[n / 3];
	if (n / 3 == 1)
		pivot[1] = buf[n / 3 + 1];
	else
	{
		if (n % 2 == 1)
			pivot[1] = buf[n / 3 * 2 - 1];
		else
			pivot[1] = buf[n / 3 * 2];
	}
	free(buf);
}

void		pick_1_pivot(t_stack *s, int *pivot, int n)
{
	int		*buf;

	buf = malloc(sizeof(int) * (n + 1));
	set_buf(buf, s, n);
	sort_buf(buf, n);
	// check_buf(buf);
	if (n % 2 == 1)
		pivot[0] = buf[n / 2 + 1];
	else
		pivot[0] = buf[n / 2];
	free(buf);
}
