#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int num;
	struct s_node *link;
} t_node;

void error()
{
	printf("Error\n");
	exit(1);
}

void push(int num, t_node **top)
{
	t_node *newnode = (t_node *)malloc(sizeof(t_node));

	newnode->num = num;
	newnode->link = *top;
	*top = newnode;
}

void push_to(t_node **a, t_node **b)
{
	t_node *top;

	top = *a;
	push(top->num, &(*b));
	*a = top->link;
	free(top);
}

void swap(t_node **top)
{
	t_node *a;
	t_node *b;

	a = *top;
	b = a->link;
	a->link = b->link;
	b->link = a;
	*top = b;
}

void rotate(t_node **top)
{
	t_node *temp;
	t_node *find;

	temp = *top;
	find = *top;
	while (find->link)
		find = find->link;
	find->link = temp;
	*top = temp->link;
	temp->link = NULL;
}

void rev_rotate(t_node **top)
{
	t_node *temp;
	t_node *find;

	temp = *top;
	find = *top;
	while (find->link)
		find = find->link;
	while (temp->link != find)
		temp = temp->link;
	temp->link = NULL;
	free(find);
	push(find->num, &(*top));
}

int main(int argc, char *argv[])
{
	t_node *a, *b;
	a = NULL;
	b = NULL;
 	int num;

//	a =  (t_node*)malloc(sizeof(t_node));

	// int ac = argc;
	// while (ac-- > 1)
	// {
	// 	if (is_num(argv[ac]) == 0)
	// 		error();
	// 	num = ft_atoi(argv[ac]);
	// 	if (num < INT_MIN || num > INT_MAX)
	// 		error();
	// 	push(num, &a);
	// }

	push(3, &a);
	push(2, &a);
	push(6, &a);
	push(5, &a);
	push(1, &a);
	push(4, &a);
	
	// print_list(a, b);

	// argc-1 들어온 숫자의 개수
	// A_to_B(6, &a, &b);
	print_list(a, b);
}
