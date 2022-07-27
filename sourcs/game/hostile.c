/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hostile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:55:12 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:39:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hostile(t_data *data)
{
	int	index;
	int	x;
	int	y;

	index = -1;
	while (data->enemies[++index])
	{
		x = data->enemies[index][0] * 44;
		y = data->enemies[index][1] * 58;
		if (data->enemies[index][2] == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->k_init, x, y);
		else if (data->enemies[index][2] == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->k_down, x, y);
		else if (data->enemies[index][2] == 2)
			mlx_put_image_to_window(data->mlx, data->win, data->k_right, x, y);
		else if (data->enemies[index][2] == 3)
			mlx_put_image_to_window(data->mlx, data->win, data->k_up, x, y);
		else if (data->enemies[index][2] == 4)
			mlx_put_image_to_window(data->mlx, data->win, data->k_left, x, y);
	}
}
