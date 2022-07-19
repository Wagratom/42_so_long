# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 18:47:53 by wwallas-          #+#    #+#              #
#    Updated: 2022/07/19 16:38:56 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLIBX_PATH				=	minilibx/
MLIBX					=	$(MLIBX_PATH)libmlx_Linux.a

LIBFT_PATH				=	libft/
LIBFT					=	$(LIBFT_PATH)libft.a

INCLUDE 				=	-I./includes -Imlx_linux -O3

SOURCS					=	main.c game_init.c data_init.c valid_map.c valid_wall.c \
							draw_map.c my_close.c filter_key.c exit.c
OBJS_DIR				=	objs
OBJS					=	$(patsubst %.c,objs/%.o,$(SOURCS)) 

CC						=	gcc
CFLAGS					=	-g3 -o3 -fPIE

MLXFLAGS				=	-Imlx_linux -lXext -L. -lX11 -lm -lz 

AR						=	ar -rcs
RM						=	rm -rf

NAME					=	so_long

VPATH					=	. srcs minilibx includes

$(OBJS_DIR)/%.o:	 	%.c 
							$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:					$(NAME)

$(NAME):				initLx $(LIBFT) $(OBJS_DIR) $(OBJS)
							$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLIBX) $(MLXFLAGS) -o $(NAME)

initLx:
							$(MAKE) -C $(MLIBX_PATH)

$(LIBFT):
							$(MAKE) -C $(LIBFT_PATH) all

$(OBJS_DIR):
							mkdir -p $@
clean:
							$(MAKE) -C $(MLIBX_PATH) clean
							$(MAKE) -C $(LIBFT_PATH) clean
							$(RM) $(OBJS_DIR)

fclean:					clean
							$(MAKE) -C $(LIBFT_PATH) fclean
							$(RM) $(NAME)

re: 					fclean all

.PHOENY:				all init clean fclean initLX libft re
