# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 21:38:45 by wwallas-          #+#    #+#              #
#    Updated: 2022/08/10 21:14:39 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT				=	./libft/libft.a
MLIBX				=	./minilibx/libmlx_Linux.a

INCLUDES			=	-I. -Imlx_linux -O3

SOURCS				=	so_long.c valid_map.c valid_chars.c creat_map.c       \
						save_positions.c game_init.c data_init.c filter_key.c \
						draw_map.c start_end_game.c collectible.c personage.c \
						hostile.c atualize_host.c close_game.c draw_movies.c  \
						verific_dead.c


OBJS_DIR			=	objetos
OBJS				=	$(patsubst %.c,objetos/%.o, $(SOURCS))

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -fPIE

MFLAGS				=	-fPIE -Imlx_linux -lXext -lX11 -lm -lz -o

NAME				=	so_long

RM					=	rm -rf

VPATH				=	./sourcs/game ./sourcs/validacions

$(OBJS_DIR)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
						make init			
						$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLIBX) $(MFLAGS) $@

$(OBJS_DIR):
						mkdir -p $@

init:
						$(MAKE) -C ./minilibx
						$(MAKE) -C ./libft

clean:
						$(MAKE) -C ./minilibx clean
						$(MAKE) -C ./libft clean
						$(RM) $(OBJS_DIR)

fclean:				clean
						$(RM) $(LIBFT)
						$(RM) $(NAME)
run:				all
						./so_long ./maps/map2.ber
re:				fclean all

.PHONY:	all clean fclean re init
