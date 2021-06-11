#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int num;
	struct s_node *link;
} t_node;

typedef struct s_stack
{
	int size;
	struct s_node *head;
} t_stack;

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_strncmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 == 0 || *str2 == 0 || *str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
void print_list(t_stack *a, t_stack *b)
{
	int i;
	t_node *temp = a->head;
	t_node *tmp = b->head;

	printf("node_CHECK ==========================================\n");
	printf("A_size = %d\n", a->size);
	for (int j=0; j < a->size; j++)
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
	for (int j=0; j < b->size; j++)
	 {
		i = 1;
		printf("B :: %d", tmp->num);
		while (i++ <= tmp->num)
			printf("_");
		tmp = tmp->link;
		printf("\n");
	}
}

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

void sort_buf(int *buf, int size)
{
	int temp;
	int i;
	int j;

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

void set_buf(int *buf, t_stack *s)
{
	int i;
	t_node *temp;

	i = 0;
	temp = s->head;
	while (i < s->size)
	{
		buf[i++] = temp->num;
		temp = temp->link;
	}
	buf[i] = '\0';
	sort_buf(buf, s->size);
}

void pick_pivot(t_stack *s, int *pivot)
{
	int *buf;

	buf = malloc(sizeof(int) * (s->size + 1));
	set_buf(buf, s);
	pivot[0] = buf[s->size / 3];
	pivot[1] = buf[s->size / 3 * 2];
	free(buf);
}

void ft_command(char *str, t_stack *s1, t_stack *s2)
{
	//commad 
}

void B_to_A(int n, t_stack *s1, t_stack *s2);

void A_to_B(int n, t_stack *s1, t_stack *s2)
{
	printf("A_to_B start\n");
	int pivot[2];
	int ra, rb, pb;

	ra = 0;
	rb = 0;
	pb = 0;
	if (n <= 3)
	{
		//simple_sort();
		return ;
	}
	pick_pivot(s1, pivot);
	while (n--)
	{
		if (s1->head->num >= pivot[1])
		{
			// ft_command("ra");
			rotate(s1);
			ra++;
		}
		else
		{
			// ft_command("pb");
			push_to(s1, s2);
			pb++;
			if (s2->head->num >= pivot[0])
			{
				// ft_command("rb");
				rotate(s2);
				rb++;
			}
		}
	}

	int i=0;
	while (i++ < ra)
		rev_rotate(s1);
		// ft_command("rra");
	i = 0;
	while (i++ < rb)
		rev_rotate(s2);
		// ft_command("rrb");

	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
	B_to_A(pb - rb, s1, s2);
}

void B_to_A(int n, t_stack *s1, t_stack *s2)
{
	printf("B_to_A start\n");
	int pivot[2];
	int ra, rb, pa;

	ra = 0;
	rb = 0;
	pa = 0;
	if (n <= 3)
	{
		//simple_sort();
		while (n--) push_to(s2, s1);
		return;
	}
	pick_pivot(s2, pivot);
	while (n--)
	{
		if (s2->head->num <= pivot[0])
		{
			rotate(s2);
			// ft_command("rb");
			rb++;
		}
		else
		{
			push_to(s2, s1);
			// ft_command("pa");
			pa++;
			if (s1->head->num <= pivot[1])
			{
				rotate(s1);
				// ft_command("ra");
				ra++;
			}
		}
	}

	A_to_B(pa - ra, s1, s2);

	int i;
	i = 0;
	while (i++ < ra)
		//ft_command("rra");
		rev_rotate(s1);
		i = 0;
	while (i++ < rb)
		//ft_command("rrb");
		rev_rotate(s2);

	A_to_B(ra, s1, s2);
	B_to_A(rb, s1, s2);
}

int main(int argc, char *argv[])
{
	t_stack *a, *b;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;

	int ac = argc;
	// while (ac-- > 1)
	// {
	// 	if (is_num(argv[ac]) == 0)
	// 		error();
	// 	num = ft_atoi(argv[ac]);
	// 	if (num < INT_MIN || num > INT_MAX)
	// 		error();
	// 	push(num, &a);
	// }

	push(3, a);
	push(24, a);
	push(2, a);
	push(44, a);
	push(6, a);
	push(5, a);
	push(-24, a);
	push(1, a);
	push(4, a);
	push(14, a);
	push(-14, a);
	print_list(a, b);

	// A_to_B(a->size, a, b);
	print_list(a, b);


}
