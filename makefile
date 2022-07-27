# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 21:38:45 by wwallas-          #+#    #+#              #
#    Updated: 2022/07/25 16:13:09 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

MLIBX_PATH			=	./minilibx
MLIBX				=	$(MLIBX_PATH)/libmlx_Linux.a

INCLUDES			=	-I. -Imlx_linux -O3

SOURCS				=	so_long.c valid_map.c valid_chars.c creat_map.c       \
						save_positions.c game_init.c data_init.c filter_key.c \
						draw_map.c start_end_game.c collectible.c personage.c \
						hostile.c atualize_host.c close_game.c draw_movies.c


OBJS_DIR			=	objetos
OBJS				=	$(patsubst %.c,objetos/%.o, $(SOURCS))

CC					=	cc
CFLAGS				=	-g3 -fPIE

MFLAGS				=	-fPIE -Imlx_linux -lXext -lX11 -lm -lz -o

NAME				=	so_long

RM					=	rm -rf

VPATH				=	./sourcs/game ./sourcs/validacions

$(OBJS_DIR)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

$(NAME):			init $(OBJS_DIR) $(OBJS)
							$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLIBX) $(MFLAGS) $@

$(OBJS_DIR):
							mkdir -p $@

init:
							$(MAKE) -C $(MLIBX_PATH)
							$(MAKE) -C $(LIBFT_PATH)

clean:
							$(MAKE) -C $(MLIBX_PATH) clean
							$(MAKE) -C $(LIBFT_PATH) clean
							$(RM) $(OBJS_DIR)

fclean:				clean
							$(RM) $(LIBFT)
							$(RM) $(NAME)

re:				fclean all


.PHONY: clean fclean re init
			
