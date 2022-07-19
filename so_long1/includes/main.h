/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:33 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 16:38:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img_background;
	void	*img_wall;
	void	*img_stopped;
	void	*img_up;
	void	*img_left;
	void	*img_down;
	void	*img_right;
	void	*img_esfera1;
	void	*img_esfera10;
	char	**layout;
	char	**exit;
	int		size_x;
	int		size_y;
	int		position[2];
	int		count_mov;
	int		direcion;
	int		collectible;
}				t_data;

typedef struct s_map_data
{
	int	collectible;
	int	position;
	int	exit;
	int size_x;
	int size_y;
	int index;
}				t_map_data;

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define EXIT 17

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

//					SPRITES_PATH

# define BACKGROUND "./sprites/background.xpm"
# define STOPPED "./sprites/stop.xpm"
# define RIGHT "./sprites/goku-right.xpm"
# define LEFT "./sprites/goku-left.xpm"
# define WALL "./sprites/nuvens.xpm"
# define ESFERA1 "./sprites/esfera1.xpm"
# define ESFERA10 "./sprites/esfera10.xpm"


int main();

int	valid_map(char *file, t_data *data);

int	valid_wall(t_data *data);

int game_init(t_data *data);

int data_init(t_data *data);

int	draw_map(t_data *data);

int filter_key(int key, t_data *data);

int my_close(t_data *data);

void	find_exit(t_data *data);

//						movimentacion
void	put_person(t_data *data, int y, int x);

//int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
//this function in to print a bit on the screen

//int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
//this function is to print a string on the screean
#endif