#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

/***** utils.c *****/				// ok
void	error();

/***** rael.c *****/
void	B_to_A(int n, t_stack *s1, t_stack *s2);
void	A_to_B(int n, t_stack *s1, t_stack *s2);
void	rrr_ab(int ra, int rb, t_stack *s1, t_stack *s2);
// void	small_A_to_B(int n, t_stack *s1, t_stack *s2);
// void	small_B_to_A(int n, t_stack *s1, t_stack *s2);
int		check_av(char *str);

/***** pivot.c *****/				// ok
void	sort_buf(int *buf, int size);
void	pick_2_pivot(t_stack *s, int *pivot);
// void	pick_1_pivot(t_stack *s, int *pivot);
void	set_buf(int *buf, t_stack *s);

/***** command.c *****/				// ok
void	push(int num, t_stack *s);
void	push_to(t_stack *a, t_stack *b);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	rev_rotate(t_stack *s);
void	ft_command(char *str, t_stack *s1, t_stack *s2);

/***** command_check.c *****/		// ok
// void	print_command(char *str);
void	ft_command_1(char *str, t_stack *s1, t_stack *s2);
void	ft_command_2(char *str, t_stack *s1, t_stack *s2);

/***** simple_check.c *****/		// ok
// void	check_012(int *s, t_stack *s1, t_stack *s2);
// void check_210(int *s, t_stack *s1, t_stack *s2);
// void	set_012(int *buf, t_stack *s1, t_stack *s2);
void	simple_sort(t_stack *s1, t_stack *s2);
void	simple_sort_b(t_stack *s1, t_stack *s2, int n);

/***** simple_sort_a.c *****/		// ok
void    simple_021(t_stack *s1, t_stack *s2);
void    simple_102(t_stack *s1, t_stack *s2);
void    simple_120(t_stack *s1, t_stack *s2);
void    simple_210(t_stack *s1, t_stack *s2);
void    simple_201(t_stack *s1, t_stack *s2);

/***** simple_sort_b.c *****/		// ok
void    b_simple_012(t_stack *s1, t_stack *s2);
void    b_simple_021(t_stack *s1, t_stack *s2);
void    b_simple_102(t_stack *s1, t_stack *s2);
void    b_simple_120(t_stack *s1, t_stack *s2);
void    b_simple_201(t_stack *s1, t_stack *s2);

# endif