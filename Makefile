NAME		=	philosophers
HEADER		=	philo.h 

SRCS		= 	main.c					\
				parsing.c				\
				init.c					\
				check_and_get_params.c	\
				error.c					\
				exec.c					\
				utils.c			

OBJS		:= $(SRCS:%.c=%.o)

CC			=	cc
FLAGS		=   -Wall -Wextra -Werror

all:		$(NAME)

$(NAME): 	print $(OBJS)
			$(CC) $(OBJS) -o $(NAME)
			@echo "\033[35m Project successfully compiled"

$(OBJS): 	%.o:%.c ${HEADER}
			@echo "\033[36m compiling: $<"
			@$(CC) $(FLAGS) -c $< -o $@

print:		
			@echo "\033[31m ~ Compiling philo ~"

clean:
	@echo "\033[31m > Removed all objects files <"
	@rm -rf *.o 

fclean: clean
	@echo "\033[31m * Removed $(NAME) *"	
	@rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re