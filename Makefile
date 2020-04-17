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

.PHONY : all clean fclean re

MAKEFLAGS += --silent

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

MAIN_FUNCS := $(shell cat files_list/main.txt)

FORMATS := $(shell cat files_list/format.txt)

MODS := $(shell cat files_list/mods.txt)

UTILS := $(shell cat files_list/utils.txt)

UTILS_FLOAT := $(shell cat files_list/utils_float.txt)

TYPES := $(shell cat files_list/types.txt)

LIBFT_FUNCTIONS := $(shell cat files_list/libft_functions.txt)

HEADERS := $(shell cat files_list/headers.txt)

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

LIBFT_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIBFT_FUNCTIONS))

MODS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(MODS))

UTILS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS))

UTILS_FLOAT_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS_FLOAT))

HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h, $(HEADERS))

OBJ = $(MAINS_OBJ) $(FORMATS_OBJ) $(TYPES_OBJ) $(LIBFT_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(UTILS_FLOAT_OBJ) $(LIBFT_OBJ)

MODE = 1

ifeq ($(MODE), 0)

all : $(NAME) objects

$(NAME):
	@ar -rs $(NAME)

objects : $(MAINS_OBJ) $(TYPES_OBJ) $(FORMATS_OBJ) $(MODS_OBJ) $(UTILS_OBJ) $(LIBFT_OBJ) $(UTILS_FLOAT_OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@

$(OBJ_DIR)%.o : $(FORMATS_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@


$(OBJ_DIR)%.o : $(TYPES_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@

$(OBJ_DIR)%.o : $(LIBFT_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@

$(OBJ_DIR)%.o : $(UTILS_FLOAT_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@ 

$(OBJ_DIR)%.o : $(MODS_DIR)%.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
	@ar -rs $(NAME) $@ 

else

all : $(OBJ)


$(OBJ_DIR)%.o : $(NAME) ;

$(NAME):
	@printf "\033[92mCompiling libftprintf...\n\033[0m"
	@make -s MODE=0
	@printf "\r                                          "
	@printf "\r\033[92mDone libftprintf[\xE2\x9C\x94]\n\033[0m"

endif
clean:
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

