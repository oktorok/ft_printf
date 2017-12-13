# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2017/12/13 02:01:41 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_realloc_printf.c 
	
FORMAT_FUNC = ft_field_func.c \
			  ft_utf_8.c

FORMAT_DIR = srcs/format_functions/

TYPE_FUNC = ft_s_func.c

TYPE_DIR = srcs/type_functions/

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
			 ft_atoi.c \
			 ft_isdigit.c \
			 ft_memset.c \
			 ft_lstnew.c \
			 ft_memalloc.c \
			 ft_putbytes.c \
			 ft_wstrlen.c

LIBFT_DIR = libft/

SRCS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(SRCS))

FORMAT_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(FORMAT_FUNC))

TYPE_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(TYPE_FUNC))

LIBFT_OBJ = $(patsubst %.c, $(LIBFT_DIR)%.o, $(LIBFT_SRCS))

OBJ = $(SRCS_OBJ) $(FORMAT_OBJ) $(TYPE_OBJ) $(LIBFT_OBJ)

OBJ_DIR = objects/

SRC_DIR = srcs/

INCLUDES_DIR = includes/

all : $(NAME)

$(NAME) : $(SRCS_OBJ) $(TYPE_OBJ) $(FORMAT_OBJ) $(LIBFT_OBJ)
	ar -rs $(NAME) $(OBJ) 
	ranlib $(NAME)

$(LIBFT_DIR)%.o : $(LIBFT_DIR)%.c
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory $(@F)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)

$(OBJ_DIR)%.o : $(FORMAT_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)

$(OBJ_DIR)%.o : $(TYPE_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)

dir_objects:
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC) $(LIBFT_OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

compile: all
	gcc $(FLAGS) prueba.c $(NAME) -I$(INCLUDES_DIR)

norme:
	norminette $(SRC) $(INCLUDES)
