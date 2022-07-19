/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:05:02 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 15:05:03 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int data_init(t_data *data)
{
	int x;
	int y;
	int		img_width;
	int		img_height;
	
	x = data->size_x * 44;
	y = data->size_y * 58;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, x, y, "teste");
	data->img_background = mlx_xpm_file_to_image(data->mlx, BACKGROUND, &img_width, &img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_height);
	data->img_stopped = mlx_xpm_file_to_image(data->mlx, STOPPED, &img_width, &img_height);
	data->img_left = mlx_xpm_file_to_image(data->mlx, LEFT, &img_width, &img_height);
	data->img_right = mlx_xpm_file_to_image(data->mlx, RIGHT, &img_width, &img_height);
	data->img_esfera1 = mlx_xpm_file_to_image(data->mlx, ESFERA1, &img_width, &img_height);
	data->img_esfera10 = mlx_xpm_file_to_image(data->mlx, ESFERA10, &img_width, &img_height);
	data->count_mov = 0;
	data->direcion = 0;
	return (0);
}