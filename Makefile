#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 14:30:13 by azaporoz          #+#    #+#              #
#    Updated: 2018/07/03 14:15:28 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
#FLAGS = -Wall -Wextra -Werror
SOURCE = main.c \
		draw.c \
		julia.c \
		mouse.c \
		helper.c \
		error.c \
		mandelbrot.c \
		keys.c \

HEADER = fractol.h
OBJECTS = $(addprefix $(OBJDIR),$(SOURCE:.c=.o))
LIBFT = include/libft.a
OBJDIR = ./obj/

all: obj $(LIBFT) $(NAME)
	@printf "\033[0;32m\nFRACTOL DONE\n\n"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c $(HEADER)
	@printf "\033[0;34m->    "
	gcc -I ./libft/ -o $@ -c $<   #flags
	@printf "\n"
#-pthread

$(NAME): $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	@make -C ./libft/
	@printf "\033[0;32m\n\n|||||||||||||||||||||\nSTART LOADING FRACTOL\n|||||||||||||||||||||\n\n\n\n"	

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJDIR)
	@make clean -C ./libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all
