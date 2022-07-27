/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:25:37 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/27 21:54:15 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>

typedef struct s_itens
{
	int	collectible;
	int	position;
	int	enemies;
	int	exit;
	int	size_x;
	int	size_y;
}			t_itens;

typedef struct s_data
{
	t_itens	itens;
	void	*mlx;
	void	*win;
	void	*background;
	void	*end;
	void	*wall;
	void	*g_init;
	void	*g_left;
	void	*g_right;
	void	*esfera;
	void	*esfera1;
	void	*portal;
	void	*portal1;
	void	*k_init;
	void	*k_up;
	void	*k_left;
	void	*k_down;
	void	*k_right;
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*none;
	char	**map;
	int		**exits;
	int		**enemies;
	int		localization[2];
	int		direcion;
	int		movements;
}		t_data;

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_PRESS 2
# define EXIT 17
# define FOCUS 9

//					numb imagens
# define ZERO "./imagens/numbs/0.xpm"
# define ONE "./imagens/numbs/1.xpm"
# define TWO "./imagens/numbs/2.xpm"
# define THREE "./imagens/numbs/3.xpm"
# define FOUR "./imagens/numbs/4.xpm"
# define FIVE "./imagens/numbs/5.xpm"
# define SIX "./imagens/numbs/6.xpm"
# define SEVEN "./imagens/numbs/7.xpm"
# define EIGHT "./imagens/numbs/8.xpm"
# define NONE "./imagens/numbs/9.xpm"

//					map imagens
# define BACKGROUND "./imagens/map/background.xpm"
# define CLOUD "./imagens/map/cloud.xpm"
# define ESFERA "./imagens/map/esfera.xpm"
# define ESFERA1 "./imagens/map/esfera1.xpm"
# define PORTAL "./imagens/map/portal.xpm"
# define PORTAL1 "./imagens/map/portal1.xpm"
# define END "./imagens/map/end.xpm"

//					personage imagens

# define G_INIT "./imagens/personagens/g_stopped.xpm"
# define G_LEFT "./imagens/personagens/g_left.xpm"
# define G_RIGHT "./imagens/personagens/g_right.xpm"
# define K_INIT "./imagens/personagens/k_init.xpm"
# define K_UP "./imagens/personagens/k_up.xpm"
# define K_LEFT "./imagens/personagens/k_left.xpm"
# define K_DOWN "./imagens/personagens/k_down.xpm"
# define K_RIGHT "./imagens/personagens/k_right.xpm"

int		valid_map(char *file, t_data *data);

int		valid_chars(int fd, t_itens *itens);

int		creat_map(int fd, t_data *data);

void	save_positions(t_data *data);

void	game_init(t_data *data);

void	data_init(t_data *data);

int		draw_map_time(t_data *data);

int		draw_map(t_data *data);

int		filter_key(int key, t_data *data);

void	*collectible(t_data *data);

void	personage(t_data *data, int x, int y);

void	draw_movies(t_data *data);

void	hostile(t_data *data);

void	atualize_host(t_data *data);

void	start_end_game(t_data *data);

void	animacion_end(t_data *data, int x, int y);

int		close_game(t_data *data);

void	put_img(t_data *data, void *img, int x, int y);

void	draw_movies_aux(t_data *data, int nb, int position);

int		del_map(char **map);

#endif
