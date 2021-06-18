#include "push_swap.h"

void push(int num, t_stack *s)
{
	t_node *newnode = malloc(sizeof(t_node));

	newnode->num = num;
	newnode->link = s->head;
	s->head = newnode;
	s->size++;
}

void push_to(t_stack *a, t_stack *b)
{
	t_node *top;

	top = a->head;
	a->size--;
	push(top->num, b);
	a->head = top->link;
	free(top);
}

void swap(t_stack *s)
{
	t_node *a;
	t_node *b;

	a = s->head;
	b = s->head->link;
	a->link = b->link;
	b->link = a;
	s->head = b;
}

void rotate(t_stack *s)
{
	t_node *temp;
	t_node *find;

	temp = s->head;
	find = s->head;
	while (find->link)
		find = find->link;
	find->link = temp;
	s->head = temp->link;
	temp->link = NULL;
}

void rev_rotate(t_stack *s)
{
	t_node *temp;
	t_node *find;

	temp = s->head;
	find = s->head;
	while (find->link)
		find = find->link;
	while (temp->link != find)
		temp = temp->link;
	temp->link = NULL;
	push(find->num, s);
	s->size--;
	free(find);
}
