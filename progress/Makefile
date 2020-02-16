# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sverona <sverona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:21:45 by sverona           #+#    #+#              #
#    Updated: 2020/02/16 23:28:55 by sverona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB_NAME = libft.a
FUNCTION = draw.c ft_lintnew.c get_coord.c main.c
O_FUNCTION = draw.o ft_lintnew.o get_coord.o main.o

all: $(NAME)

$(LIB_NAME):
	@make -C libft/ $(LIBFT)

$(NAME): $(LIB_NAME)
	@gcc -g -lmlx -framework OpenGL -framework AppKit g_n_l/get_next_line.c -c $(FUNCTION)
	@gcc $(O_FUNCTION) -L libft/ -lft -o $(NAME)
clean:
	@rm -f *.o
	@make -C libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	
re: fclean all