# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2017/12/08 00:10:57 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_realloc_printf.c \
	   ft_sS_func.c 

SRCS_PATH = $(patsubst %.c, srcs/%.c,$(SRCS))

LIBFT_SRCS = ft_strncpy.c \
			 ft_putstr.c \
			 ft_strnew.c \
			 ft_strlen.c \
			 ft_putnbr.c \
			 ft_putchar.c \
			 ft_strsub.c \
			 ft_strdup.c \
			 ft_strjoin.c \
			 ft_strcat.c \
			 ft_memcpy.c \
			 ft_atoi.c

LIBFT_DIR = libft/

OBJ_SRC = $(patsubst %.c, $(OBJ_DIR)%.o,$(SRCS))

LIBFT_OBJ = $(patsubst %.c, $(LIBFT_DIR)%.o, $(LIBFT_SRCS))

OBJ_DIR = objects/

SRC_DIR = srcs/

INCLUDES_DIR = includes/

all : $(NAME)

$(NAME) : $(OBJ_SRC) $(LIBFT_OBJ)
	ar -rs $(NAME) $(OBJ_SRC) $(LIBFT_OBJ) 
	ranlib $(NAME)

$(LIBFT_DIR)%.o : $(LIBFT_DIR)%.c
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory $(@F)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC) $(LIBFT_OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

compile: all
	gcc $(FLAGS) prueba.c $(NAME) -I$(INCLUDES_DIR)

norme:
	norminette $(SRC) $(INCLUDES)
