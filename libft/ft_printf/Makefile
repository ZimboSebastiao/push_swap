CC = cc
AR = ar 
ARFLAG = rcs
FLAGS = -Wall -Wextra -Werror -I includes

SRC = ft_printf.c \
		ft_utils.c \
		ft_utils_hard.c

OBJECTS = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $(ARFLAG) $(NAME) $(OBJECTS)

%.o: %.c libftprintf.h
		$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all