NAME = push_swap

NAME2 = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = 	./libft/ft_strcmp.c\
		./libft/ft_putchar_fd.c\
		./libft/ft_putstr_fd.c\
		./libft/ft_strlen.c\
		./libft/ft_strchr.c\
		./libft/ft_split.c\
		./libft/ft_atoi.c\
		main.c\
		push_swap.c\
		pivot.c\
		utils.c\
		cmd.c\
		cmd_check.c\
		simple_sort_check.c\
		simple_sort_a.c\
		simple_sort_b.c

SRCS_CK =	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			./libft/ft_strcmp.c\
			./libft/ft_putchar_fd.c\
			./libft/ft_putstr_fd.c\
			./libft/ft_strlen.c\
			./libft/ft_strchr.c\
			./libft/ft_split.c\
			./libft/ft_atoi.c\
			./libft/ft_strdel.c\
			./libft/ft_strstr.c\
			checker.c\
			pivot.c\
			utils.c\
			cmd.c\
			cmd_check.c\

all : $(NAME) $(NAME2)

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

$(NAME2) :
	make all -C libft
	$(CC) $(CFLAGS) -o $(NAME2) $(SRCS_CK)


fclean : clean
	$(RM) $(NAME) $(NAME2)
	make fclean -C libft/

clean :
	$(RM) $(NAME) $(NAME2)
	make clean -C libft/

re_$(NAME) : fclean $(NAME)

re_$(NAME2) : fclean $(NAME2)

re : fclean all