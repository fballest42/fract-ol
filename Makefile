# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2021/06/10 13:35:55 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #

.DELETE_ON_ERROR:

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	LIBS := -lz -framework OpenGL -framework AppKit
	MLX = minilibx/libmlx.dylib
	MINILIBX = minilibx
	INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif

# FILE NAME #

NAME = fractol

# SOURCES #

SRC = 	ft_fractolmain ft_juliafractol ft_mandelfractol ft_utils

SRCCUB = $(addsuffix .c, $(SRC))
OBJS = $(SRCCUB:.c=.o)

LIBFT = libft/libft.a

# COMPILER #

CC = gcc -Wall -Wextra -Werror -g

# COLOUR DEFINITION #

BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING MINILIBX==========$(RESET)"
	@make -C ${MINILIBX}
	@echo "$(BLUE)==========CREATING FRACTOL==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) $(MLX) ${LIBS} -o ${NAME}
	@echo "Done"
	@echo "$(BLUE)==========COPY LIBMLX.DYLIB==========$(RESET)"
	@cp ${MLX} ./
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating fractol file"

clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@make -C $(MINILIBX)/ clean
	@make -C libft/ clean
	@$(RM) ${LIBFT}
	@${RM} libmlx.dylib
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@$(RM) *.bmp
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re shell addsuffix
