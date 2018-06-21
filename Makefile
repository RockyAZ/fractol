#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 14:30:13 by azaporoz          #+#    #+#              #
#    Updated: 2018/06/19 14:30:14 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
#FLAGS = -Wall -Wextra -Werror
SOURCE = main.c mandelbrot.c draw.c julia.c mouse.c helper.c error.c

HEADER = fractol.h
OBJECTS = $(addprefix $(OBJDIR),$(SOURCE:.c=.o))
LIBFT = include/libft.a
OBJDIR = ./obj/

all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c $(HEADER)
	@printf "\033[0;34m T_T\n"
	gcc -I ./libft/ -o $@ -c $<   #flags

$(NAME): $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	@make -C ./libft/

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJDIR)
	@make clean -C ./libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all
