NAME = push_swap

# NAME2 = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = 	real.c\
		./libft/ft_strcmp.c\
		./libft/ft_putchar_fd.c\
		./libft/ft_putstr_fd.c\
		./libft/ft_strlen.c\
		./libft/ft_strchr.c\
		./libft/ft_split.c\
		./libft/ft_atoi.c\
		pivot.c\
		utils.c\
		command.c\
		command_check.c\
		simple_check.c\
		simple_sort_a.c\
		simple_sort_b.c

# SRCS_CK =	checker.c\
# 			gnl/get_next_line.c\
# 			gnl/get_next_line_utils.c\
# 			
# 			./libft/ft_strstr.c\
# 			./libft/ft_memset.c\
# 			./libft/ft_atoi.c\
# 			
# 			srcs/util.c\
# 			srcs/util2.c\
# 			cmd.c\
# 			cmd2.c\
# 			build.c

all : $(NAME) $(NAME2)

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

# $(NAME2) :
# 	make all -C libft
# 	$(CC) $(CFLAGS) -o $(NAME2) $(SRCS_CK)


fclean : clean
	$(RM) $(NAME) $(NAME2)
	make fclean -C libft/

clean :
	$(RM) $(NAME) $(NAME2)
	make clean -C libft/

re_$(NAME) : fclean $(NAME)

# re_$(NAME2) : fclean $(NAME2)

re : fclean all