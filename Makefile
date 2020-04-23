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

DEPDIR := .deps

FLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

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

VPATH = $(TYPES_DIR):$(FORMATS_DIR):$(MODS_DIR):$(UTILS_DIR):$(LIBFT_DIR):$(UTILS_FLOAT_DIR):$(MAINS_DIR):$(INCLUDES_DIR)

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

FILE_CHECK := $(wildcard $(NAME))

#====================MODE 0 ============================
ifeq ($(MODE), 0)

all : $(NAME)

$(NAME): $(OBJ)

$(OBJ_DIR)%.o : %.c $(HEADER_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)
ifneq ("$(FILE_CHECK)", "")
		@ar -rc $(NAME) $@
endif

else
#===================MODE 1 ===========================
$(NAME): $(OBJ) 
ifeq ("$(FILE_CHECK)", "")
	@printf "\033[92mGenerating libftprintf...\n\033[0m"
	@ar -rcs $(NAME) $(OBJ)
	@printf "\r\033[92mDone Generating[\xE2\x9C\x94]\n\033[0m"
else
	@ranlib $(NAME)
endif

$(OBJ_DIR)%.o : %.c $(HEADER_PATH)
ifneq ("$(FILE_CHECK)", "")
	@printf "\033[92mUpdating libftprintf...\n\033[0m"
	@$(MAKE) MODE=0
	@printf "\r                                          "
	@printf "\r\033[92mDone Updating[\xE2\x9C\x94]\n\033[0m"
else
	@printf "\033[92mCompiling libftprintf objects...\n\033[0m"
	@$(MAKE) MODE=0
	@printf "\r                                          "
	@printf "\r\033[92mDone Compiling[\xE2\x9C\x94]\n\033[0m"
endif

endif
#=================NO MODE ==========================
clean:
	@printf "\033[92m<< Cleaning $(NAME) >>\n\033[0m"
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)

fclean: clean
	@printf "\r\033[92m<< Fcleaning $(NAME) >>\n\033[0m"
	rm -f $(NAME)

re: fclean
	make

