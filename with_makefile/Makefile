# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sverona <sverona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:21:45 by sverona           #+#    #+#              #
#    Updated: 2020/02/25 19:17:02 by sverona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g
SRC_DIR = src/
INC_DIR = includes/
LIB_DIR = libft/
LIB_NAME = libft.a
SRCS = *.c
INCS = *.h
OBJ = $(SRCS:.c=.o)
NAME = fdf

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	@make -C $(LIB_DIR) $(LIB_NAME)

$(NAME): $(LIB_NAME)
	@gcc -c $(SRC_DIR)$(SRCS) -I $(INC_DIR) -I $(LIB_DIR) $(FLAGS)
	@gcc $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft -lmlx -framework OpenGL -framework AppKit

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all