# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 21:53:27 by jinam             #+#    #+#              #
#    Updated: 2022/11/10 18:15:42 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

# commands 

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf 

# dirs 

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
OBJCS_DIR = objcs

# src files

LIBFT_FILES =	ft___lst_bonus \
				ft___lst_del_bonus \
				ft___lst_function_bonus \
				ft__print_functions \
				ft__stdlib \
				ft__string \
				ft__string_function \
				ft__string_split \
				ft_atol_base \
				ft_ctype_case_mapping \
				ft_ctype_classification \
				ft_stdlib \
				ft_string_atoi_base \
				ft_string_comparison \
				ft_string_concat \
				ft_string_copying \
				ft_string_duplicate \
				ft_string_itoa_base \
				ft_string_miscellaneous \
				ft_string_search \
				ft_string_temp \
				ft_malloc \
				ft_string_temp_function \
				ft_atof

PRINTF_FILES = 	_printf_c \
				_printf_d \
				_printf_p \
				_printf_s \
				_printf_u \
				_printf_x \
				ft_printf \
				ft_printf_common_utils \
				ft_printf_nbr_utils

GNL_FILES = 	get_next_line_bonus \
				get_next_line_utils_bonus

# objects

LIBFT_OBJCS		=	$(addprefix $(OBJCS_DIR)/$(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT_FILES)))
PRINTF_OBJCS	=	$(addprefix $(OBJCS_DIR)/$(PRINTF_DIR)/, $(addsuffix .o, $(PRINTF_FILES)))
GNL_OBJCS		=	$(addprefix $(OBJCS_DIR)/$(GNL_DIR)/, $(addsuffix .o, $(GNL_FILES)))

# options 

ifdef WITH_PRINTF
	P_OBJCS = $(PRINTF_OBJCS)
endif

ifdef WITH_GNL
	G_OBJCS = $(GNL_OBJCS)
endif

.PHONY : all printf gnl clean fclean re

all : $(NAME)

$(NAME)	:	$(LIBFT_OBJCS) $(P_OBJCS) $(G_OBJCS)
	@$(AR) $(ARFLAGS) $@ $^

# make directorys

$(OBJCS_DIR)/$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(LIBFT_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(PRINTF_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(GNL_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@


printf : 
	@make WITH_PRINTF=1 all

gnl : 
	@make WITH_GNL=1 all

printf_gnl:
	@make WITH_PRINTF=1 WITH_GNL=1 all

clean : 
	$(RM) $(RMFLAGS) $(OBJCS_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all
