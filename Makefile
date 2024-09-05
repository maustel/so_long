# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 15:52:44 by maustel           #+#    #+#              #
#    Updated: 2024/06/06 15:20:34 by maustel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

FLAGS := -Wall -Werror -Wextra

HEADERS := -I./libs/libft \
		-I./libs/get_next_line \
# linux -I./MLX42/include/MLX42

MLX42_Flags := -lglfw -framework Cocoa -framework IOKit -framework OpenGL
# linux MLX42_Flags := -ldl -lglfw -pthread -lm

LIBFT = ./libs/libft/libft.a
MLX42 = ./MLX42/build/libMLX42.a

SRCS :=	main.c free_all.c init.c init_helper.c parsing.c map_check.c map_check_helper.c \
		start_game.c \
		./libs/get_next_line/get_next_line.c \
		./libs/get_next_line/get_next_line_utils.c \

OBJS := $(SRCS:.c=.o)

# Git repo which traces mem leaks without conflicting with MLX.
LEAK_FINDER = -L./leak_finder -lft_malloc
LEAK_FINDER_INCLUDE = -I./leak_finder/includes
LEAK_FINDER_REPO = https://github.com/iwillenshofer/leak_finder.git

all:	mlx_clone $(NAME)

$(NAME):	$(LIBFT) $(MLX42) $(OBJS)
	cc $(FLAGS) $(HEADERS)$(MLX42_Flags) $(OBJS) -o $(NAME) $(LIBFT) $(MLX42)
# linux cc $(FLAGS) $(HEADERS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX42) $(MLX42_Flags)

leaks:	mlx_clone $(LIBFT) $(MLX42) $(LEAK_FINDER) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX42_Flags) $(MLX42) $(LEAK_FINDER) $(LIBFT) -o $(NAME)

%.o: %.c
	cc $(FLAGS) $(HEADERS) $(LEAK_FINDER_INCLUDE) -c $< -o $@

$(LIBFT):
	make -C libs/libft

mlx_clone:
	@if [ -d "MLX42" ]; then \
		echo "MLX42 directory already exists."; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42 && cmake -B build && cd build && make && cd ../..;\
	fi

$(LEAK_FINDER):
	@if [ -d ./leak_finder/ ]; then \
		echo "[leak_finder] already exists!"; \
	else \
		echo "	Cloning [leak_finder library]"; \
		git clone $(LEAK_FINDER_REPO) leak_finder; \
	fi
	@echo "Compiling [leak_finder]..."
	@$(MAKE) -C ./leak_finder
	@cp ./leak_finder/libft_malloc.so ./
	@cp ./leak_finder/libft_malloc_x86_64_Darwin.so ./
	@echo "To use leak_finder: \
	- include 'malloc.h' on the VERY TOP of your main header (will substitute the malloc()) \
	- Use the appropriate functions print_leaks() (show_alloc_mem_ex()) at the exit points"

clean:
	make clean -C libs/libft
	rm -f $(OBJS)

fclean:	clean
	make fclean -C libs/libft
	rm -f $(NAME)

destroy: fclean
	rm -rf ./MLX42
	rm -rf ./leak_finder ./libft_malloc.so ./libft_malloc_x86_64_Darwin.so

re:	fclean all

.PHONY:	all clean fclean re mlx_clone leaks destroy
