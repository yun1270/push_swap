#include "push_swap.h"

void		push(int num, t_stack *s)
{
	t_node	*newnode = malloc(sizeof(t_node));

	newnode->num = num;
	newnode->link = s->head;
	s->head = newnode;
	s->size++;
}

void		push_to(t_stack *s1, t_stack *s2)
{
	t_node	*top;

	if (s1->size == 0)
		error(s1, s2);
	top = s1->head;
	s1->size--;
	push(top->num, s2);
	s1->head = top->link;
	free(top);
}

void		swap(t_stack *s1, t_stack *s2)
{
	t_node	*a;
	t_node	*b;

	if (s1->size == 0)
		error(s1, s2);
	a = s1->head;
	b = s1->head->link;
	a->link = b->link;
	b->link = a;
	s1->head = b;
}

void		rotate(t_stack *s1, t_stack *s2)
{
	t_node	*temp;
	t_node	*find;

	if (s1->size == 0)
		error(s1, s2);
	temp = s1->head;
	find = s1->head;
	while (find->link)
		find = find->link;
	find->link = temp;
	s1->head = temp->link;
	temp->link = NULL;
}

void		rev_rotate(t_stack *s1, t_stack *s2)
{
	t_node	*temp;
	t_node	*find;

	if (s1->size == 0)
		error(s1, s2);
	temp = s1->head;
	find = s1->head;
	while (find->link)
		find = find->link;
	while (temp->link != find)
		temp = temp->link;
	temp->link = NULL;
	push(find->num, s1);
	s1->size--;
	free(find);
}
