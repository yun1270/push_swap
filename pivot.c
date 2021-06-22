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

void		set_buf(int *buf, t_stack *s)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = s->head;
	while (i < s->size)
	{
		buf[i++] = temp->num;
		temp = temp->link;
	}
	buf[i] = '\0';
}

void		pick_2_pivot(t_stack *s, int *pivot)
{
	int		*buf;

	buf = malloc(sizeof(int) * (s->size + 1));
	set_buf(buf, s);
	sort_buf(buf, s->size);
	pivot[0] = buf[s->size / 3 + 1];
	if (s->size % 2 == 1)
		pivot[1] = buf[s->size / 3 * 2 - 1];
	else
		pivot[1] = buf[s->size / 3 * 2];
	free(buf);
}

void		pick_1_pivot(t_stack *s, int *pivot)
{
	int		*buf;

	buf = malloc(sizeof(int) * (s->size + 1));
	set_buf(buf, s);
	sort_buf(buf, s->size);
	if (s->size % 2 == 1)
		pivot[0] = buf[s->size / 2 + 1];
	else
		pivot[0] = buf[s->size / 2];
	free(buf);
}
