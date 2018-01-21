# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/01/21 21:35:40 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

NAME = libftprintf.a

FLAGS =

MAIN_FUNCS = ft_printf.c \
	 		 ft_realloc_printf.c 

FORMATS = ft_field_format.c \
		  ft_minus_format.c \
		  ft_space_format.c \
		  ft_plus_format.c \
		  ft_apostrophe_format.c \
		  ft_zero_format.c

MODS = ft_l_mod.c 

UTILS = ft_wchar.c \
		ft_utf8.c \
		ft_locate_pointer.c \
		ft_locate_date.c \
		ft_choose_power.c \
		ft_dtomyd.c \
		ft_sige.c \
		ft_take_power.c \
		ft_multiply.c \
		ft_grisu.c

TYPES = ft_s_type.c \
		ft_c_type.c \
		ft_ws_type.c \
		ft_wc_type.c \
		ft_i_type.c


LIBFT_FUNCTIONS = ft_strncpy.c \
				  ft_strcpy.c \
				  ft_putstr.c \
	 			  ft_strnew.c \
		 		  ft_strlen.c \
	 			  ft_putnbr.c \
	 			  ft_putchar.c \
	 			  ft_strsub.c \
	 			  ft_strdup.c \
	 			  ft_strjoin.c \
	 			  ft_strjoinfree.c \
	 			  ft_strcat.c \
	 			  ft_memcpy.c \
	 			  ft_atoi.c \
	 			  ft_isdigit.c \
	 			  ft_memset.c \
	 			  ft_lstnew.c \
	 			  ft_memalloc.c \
	 			  ft_putbytes.c \
	 			  ft_wstrlen.c \
	 			  ft_strdel.c \
	 			  ft_strchr.c \
	 			  ft_strnjoin.c \
	 			  ft_strlen_free.c \
	 			  ft_memalloc.c \
	 			  ft_memdel.c \
				  ft_strstr.c \
				  ft_itoa.c

TYPES_DIR = srcs/types/

FORMATS_DIR = srcs/formats/

MODS_DIR = srcs/mods/

UTILS_DIR = srcs/utils/

LIBFT_DIR = libft/

OBJ_DIR = objects/

MAINS_DIR = srcs/

MAINS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))

FORMATS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(FORMATS))

TYPES_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(TYPES))

LIBFT_OBJ = $(patsubst %.c, $(LIBFT_DIR)%.o, $(LIBFT_FUNCTIONS))

MODS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(MODS))

UTILS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS))

OBJ = $(MAINS_OBJ) $(FORMATS_OBJ) $(TYPES_OBJ) $(LIBFT_OBJ) $(MODS_OBJ) $(UTILS_OBJ)

INCLUDES_DIR = includes/

all : $(NAME)

$(NAME) : $(MAINS_OBJ) $(TYPES_OBJ) $(FORMATS_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

$(LIBFT_DIR)%.o : $(LIBFT_DIR)%.c
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory $(@F)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(FORMATS_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(TYPES_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(MODS_DIR)%.c | dir_objects
	gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	mv -f $(@F) $(OBJ_DIR)
	ar -rs $(NAME) $@ 

dir_objects:
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC) $(LIBFT_OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

compile:
	make
	gcc $(FLAGS) prueba.c $(NAME) -I$(INCLUDES_DIR)
