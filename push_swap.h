#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct		s_node
{
	int				num;
	struct s_node	*link;
}					t_node;

typedef struct		s_stack
{
	int				size;
	struct s_node	*head;
}					t_stack;

void print_list(t_stack *s1, t_stack *s2);

// int					stack_is_sorted(t_stack *s1);

/***** push_swap.c *****/
// void				move_a_to_b(int n, int *pivot, t_stack *s1, t_stack *s2);
// void				move_b_to_a(int n, int *pivot, t_stack *s1, t_stack *s2);
// void				rrr_ab(int ra, int rb, t_stack *s1, t_stack *s2);
// void				re(int n, int ra, int rb, int pa, int pb, t_stack *s1, t_stack *s2);
void				B_to_A(int n, t_stack *s1, t_stack *s2);
void				A_to_B(int n, t_stack *s1, t_stack *s2);

/***** utils.c *****/ // ok
void				error(t_stack *s1, t_stack *s2);
void				check_buf(t_stack *s1, t_stack *s2);
// int				check_av(char *str);
// int				ft_avlen(char **av);
void				set_stack(int ac, char **av, t_stack *s1, t_stack *s2);

/***** pivot.c *****/ // ok
void				sort_buf(int *buf, int size);
void				pick_2_pivot(t_stack *s, int *pivot, int n);
void				pick_1_pivot(t_stack *s, int *pivot, int n);
void				set_buf(int *buf, t_stack *s, int n);

/***** command.c *****/ // ok
void				push(int num, t_stack *s);
void				push_to(t_stack *s1, t_stack *s2);
void				swap(t_stack *s, t_stack *s2);
void				rotate(t_stack *s, t_stack *s2);
void				rev_rotate(t_stack *s, t_stack *s2);

/***** command_check.c *****/ // ok
// void				print_command(char *str);
int					ft_command_1(int n, char *str, t_stack *s1, t_stack *s2);
int					ft_command_2(int n, char *str, t_stack *s1, t_stack *s2);

/***** simple_sort_check.c *****/ // ok
// static void		set_buf_simple(int *buf, t_stack *s);
// static void		check_012(int *s, t_stack *s1, t_stack *s2);
// static void		check_210(int *s, t_stack *s1, t_stack *s2);
// static void		set_012(int *buf, t_stack *s1, t_stack *s2);
void				sort_small(int n, t_stack *s1, t_stack *s2);
void				simple_sort(t_stack *s1, t_stack *s2, char st);

/***** simple_sort_a.c *****/ // ok
void				ft_command_ss(int n, t_stack *s1, t_stack *s2);
void				simple_021(t_stack *s1, t_stack *s2);
void				simple_102(t_stack *s1, t_stack *s2);
void				simple_120(t_stack *s1, t_stack *s2);
void				simple_210(t_stack *s1, t_stack *s2);
void				simple_201(t_stack *s1, t_stack *s2);

/***** simple_sort_b.c *****/ // ok
void				b_simple_012(t_stack *s1, t_stack *s2);
void				b_simple_021(t_stack *s1, t_stack *s2);
void				b_simple_102(t_stack *s1, t_stack *s2);
void				b_simple_120(t_stack *s1, t_stack *s2);
void				b_simple_201(t_stack *s1, t_stack *s2);
void				b_simple_210(t_stack *s1, t_stack *s2);

# endif