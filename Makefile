# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 16:35:47 by jinam             #+#    #+#              #
#    Updated: 2025/02/11 16:53:27 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -O3 -Wall -Wextra -Werror
TARGET = miniRT
SRCS = main
SRC_DIR = srcs
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

LIBDIR = ./libft
MLXDIR = ./minilibx-linux
MLX_LIB = libmlx_Linux.a

all:$(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C$(LIBDIR) printf_gnl
	$(MAKE) -C$(MLXDIR) all
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBDIR) -lft -L$(MLXDIR) -lmlx -lX11 -lXext -lm
	ln -s $(MLXDIR)/$(MLX_LIB) .

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR) -I$(MLXDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(LIBDIR)/libft.a
	@rm -rf $(TARGET)
	@rm -rf ./$(MLX_LIB)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
