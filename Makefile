# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:48:43 by amirfatt          #+#    #+#              #
#    Updated: 2023/12/05 15:32:34 by amirfatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
CC= cc

FLAGS= -g -Wall -Wextra -Werror
MLX_INCL= -L/usr/lib
MLX_FLAGS= -lmlx -lXext -lX11

INCLUDE= -I includes
LIBFT= cd includes/libft && make
FT_PRINTF= cd includes/ft_printf && make

SRC=  so_long.c valid_map.c render_map.c manage_game.c init_map.c init_graphics.c free_game.c error_msg.c check_map.c 
SRC_PATH= $(addprefix source/, $(SRC))

OBJECTS= $(SRC_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(OBJECTS) -o $(NAME) includes/libft/libft.a includes/ft_printf/libftprintf.a $(MLX_INCL) $(MLX_FLAGS)
	@echo "------------GAME Creation------------"

%.o: %.c
	$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS)
	cd includes/libft && make clean
	cd includes/ft_printf && make clean
	@echo "------------Object files deletion------------"

fclean: clean
	rm -f $(NAME)
	cd includes/libft && make fclean
	cd includes/ft_printf && make fclean 
	@echo "------------Exec files deletion------------"

re: fclean all

.PHONY: all clean fclean re
