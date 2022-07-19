/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:09:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 16:21:15 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	put_map(t_data *data, void *img, int x, int y)
{
	static int	i = 0;

	if (i == 0)
	{
		i++;
		mlx_put_image_to_window(data->mlx, data->win, img, x, y + i);
	}
	else
	{
		i--;
		mlx_put_image_to_window(data->mlx, data->win, img, x, y + i);
	}
}

void	put_person(t_data *data, int y, int x)
{
	int	direcion;

	x *= 44;
	y *= 58;
	direcion = data->direcion;
	if (direcion == 0)
		put_map(data, data->img_stopped, x, y);
	else if (direcion == 2)
		put_map(data, data->img_left, x, y);
	else
		put_map(data, data->img_right, x, y);
}

void	put_collectable(t_data *data, int y, int x)
{
	static int	i = 0;

	x *= 48;
	y *= 67;
	if (i == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_esfera1, x, y);
		i = 0;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_esfera10, x, y);
		i++;
	}
}

void	put_wall(t_data *data, int x, int y)
{
	x *= 44;
	y *= 58;
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x, y);
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	mlx_put_image_to_window(data->mlx, data->win, data->img_background, 0, 0);
	while (data->layout[++y])
	{
		x = -1;
		while (data->layout[y][++x])
		{
			if (data->layout[y][x] == '1')
				put_wall(data, x, y);
			else if(data->layout[y][x] == 'C')
				put_collectable(data, y, x);
			else if (data->layout[y][x] == 'P')
				put_person(data, y, x);
		/* 	if (data->collectible == 0)
				end_game(data); */
		}
	}
	return (0);
}
