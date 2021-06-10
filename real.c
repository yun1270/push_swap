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
	free(find);
	push(find->num, s);
}

static void sort_buf(int *buf, int size)
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
		buf[i] = temp->num;
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

// void A_to_B(int n, t_node *s1, t_node *s2)
// {
//     int pivot[2];
//     int ra, rb, pb;
//     t_node  *a, *b;

//     a = s1->head;
//     b = s2->head;
//     ra = 0;
//     rb = 0;
//     pb = 0;
//     if (n <= 3)
//     {
//         //simple_sort();
//         return ;
//     }
//     pick_pivot(a, pivot);
//     // 적절한 피봇 2개 선택
//     // pivot[0] - 작은 피봇 , pivot[1] - 큰 피봇
//     while (n-- > 0)
//     {
//         if (a->num >= pivot[1])          // [3]
//         {
//             ft_command("ra");
//             ra++;
//         }
//         else                        // [2] [1]
//         {
//             ft_command("pb");
//             pb++;
//             if (b->num >= pivot[0])      // [2]
//             {
//                 ft_command("rb");
//                 rb++;
//             }
//         }
//     }
//     // A :: [3] [정렬]
//     // B :: [1] [고정] [2]

//     int i;
//     i = 0;
//     while (i++ < ra)
//         ft_command("rra");
//     while (i++ < rb)
//         ft_command("rrb");
//     // A :: [3] [정렬]
//     // B :: [2] [1] [고정]

//     A_to_B(ra, s1, s2);                // [3] ~> [3_1] [3_2] [3_3]
//     B_to_A(rb, s1, s2);                // [2]
//     B_to_A(pb - rb, s1, s2);           // [1]
// }

// void B_to_A(int n, t_node *s1, t_node *s2)
// {
//     int pivot[2];
//     int ra, rb, pa;
//     t_node *a, *b;

//     a = s1->head;
//     b = s2->head;
//     ra = 0;
//     rb = 0;
//     pa = 0;
//     if (n <= 3)
//     {
//         //simple_sort();
//         return ;
//     }
//     pick_pivot(b, pivot);
//     // 적절한 피봇 2개 선택
//     // pivot[0] - 작은 피봇 , pivot[1] - 큰 피봇
//     while (n-- > 0)
//     {
//         if (b->num <= pivot[0])          // [3_1]
//         {
//             ft_command("rb");
//             rb++;
//         }
//         else                        // [3_2] [3_3]
//         {
//             ft_command("pa");
//             pa++;
//             if (a->num <= pivot[1])      // [3_2]
//             {
//                 ft_command("ra");
//                 ra++;
//             }
//         }
//     }
//     // A :: [3_3] [정렬] [3_2]
//     // B :: [3_1] [고정]

//     A_to_B(pa - ra, s1, s2);                           // [3]

//     int i;
//     i = 0;
//     while (i++ < ra)
//         ft_command("rra");
//     while (i++ < rb)
//         ft_command("rrb");
//     // A :: [3_2] [3_3] [정렬]
//     // B :: [3_1] [고정]

//     A_to_B(ra, s1, s2);           // [2]
//     B_to_A(rb, s1, s2);           // [1]
// }

void print_list(t_stack *a, t_stack *b)
{
	int i = 0;
	t_node *temp = a->head;
	t_node *tmp = b->head;

	printf("node_CHECK ==========================================\n");
	printf("A_size = %d\n", a->size);
	while (temp)
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
	while (tmp)
	{
		i = 1;
		printf("B :: %d", tmp->num);
		while (i++ <= tmp->num)
			printf("_");
		tmp = tmp->link;
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	t_stack *a, *b;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;

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

	push(3, a);
	push(2, a);
	push(6, a);
	push(5, a);
	push(1, a);
	push(4, a);
	print_list(a, b);
}
