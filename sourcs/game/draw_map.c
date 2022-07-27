/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:56:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:48:10 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

int	draw_map_time(t_data *data)
{
	static int	time = 0;
	static int	j = 0;

	time++;
	if (time > 20000)
	{
		draw_map(data);
		draw_movies(data);
		j++;
		if (j > 1)
		{
			atualize_host(data);
			draw_movies(data);
			j = 0;
		}
		time = 0;
	}
	return (0);
}

int	draw_map(t_data *data)
{
	int	y;
	int	x;

	mlx_put_image_to_window(data->mlx, data->win, data->background, 0, 0);
	if (data->itens.collectible == 0)
		animacion_end(data, data->itens.size_x * 14, data->itens.size_y * 20);
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
				put_img(data, data->wall, x * 44, y * 58);
			else if (data->map[y][x] == 'C')
				put_img(data, collectible(data), x * 44, y * 58);
			else if (data->map[y][x] == 'P')
				personage(data, x * 44, y * 58);
			hostile(data);
			if (data->itens.collectible == 0)
				start_end_game(data);
		}
	}
	return (0);
}
