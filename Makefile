# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/06/08 19:06:14 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

MAIN_FUNCS = $(shell cat files_list/main.txt)

FORMATS = $(shell cat files_list/formats.txt)

MODS = $(shell cat files_list/mods.txt)

UTILS = $(shell cat files_list/utils.txt)

UTILS_FLOAT = $(shell cat files_list/utils_float.txt)

TYPES = $(shell cat files_list/types.txt)

LIBFT_FUNCTIONS = $(shell cat files_list/types.txt)

HEADERS = $(shell cat files_list/headers.txt)

TYPES_DIR = srcs/types/

FORMATS_DIR = srcs/formats/

MODS_DIR = srcs/mods/

UTILS_DIR = srcs/utils/

LIBFT_DIR = srcs/libft/

OBJ_DIR = objects/

UTILS_FLOAT_DIR = $(UTILS_DIR)utils_float/

MAINS_DIR = srcs/

INCLUDES_DIR = includes/

MAINS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))

FORMATS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(FORMATS))

TYPES_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(TYPES))

LIBFT_OBJ = $(patsubst %.c, $(LIBFT_DIR)%.o, $(LIBFT_FUNCTIONS))

MODS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(MODS))

UTILS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS))

LIBFT_OBJ = $(parsubsts %.c, $(OBJ_DIR)%.o, $(LIBFT))

UTILS_FLOAT_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS_FLOAT))

HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h, $(HEADERS))

OBJ = $(MAINS_OBJ) $(FORMATS_OBJ) $(TYPES_OBJ) $(LIBFT_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(UTILS_FLOAT_OBJ) $(LIBFT_OBJ)


all : $(NAME)

$(NAME) : $(MAINS_OBJ) $(TYPES_OBJ) $(FORMATS_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(LIBFT_OBJ) $(UTILS_FLOAT_OBJ)
	ranlib $(NAME)

$(LIBFT_DIR)%.o : $(LIBFT_DIR)%.c 
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory $(@F)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(FORMATS_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(TYPES_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@

$(OBJ_DIR)%.o : $(LIBFT_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@

$(OBJ_DIR)%.o : $(UTILS_FLOAT_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(MODS_DIR)%.c $(HEADER_PATH)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

clean:
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

compile:
	make
	gcc $(FLAGS) prueba.c $(NAME) -I$(INCLUDES_DIR)

compile2:
	make
	gcc $(FLAGS) prueba2.c $(NAME) -I$(INCLUDES_DIR)
