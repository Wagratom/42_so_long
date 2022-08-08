/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:23:54 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/08 16:16:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verif_end(t_data *data);

void	animacion_end(t_data *data, int x, int y)
{
	static int	time = 0;
	int			i;

	if (time == 0)
	{
		i = 0;
		while (i++ <= 100000)
			mlx_put_image_to_window(data->mlx, data->win, data->end, x, y);
	}
	time++;
}

void	atualize_portal(t_data *data)
{
	int	index;

	index = -1;
	while (data->exits[++index])
	{
		if (data->exits[index][2] == 0)
			data->exits[index][2] = 1;
		else
			data->exits[index][2] = 0;
	}
}

void	start_end_game(t_data *data)
{
	int			x;
	int			y;
	int			index;

	index = -1;
	while (data->exits[++index])
	{
		x = data->exits[index][0] * 44;
		y = data->exits[index][1] * 58;
		if (data->exits[index][2] == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->portal, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->portal1, x, y);
	}
	verif_end(data);
}

void	verif_end(t_data *data)
{
	int	index;

	index = -1;
	animacion_end(data, data->itens.size_x * 14, data->itens.size_y * 20);
	while (data->exits[++index])
	{
		if (data->exits[index][0] == data->localization[0] &&
			data->exits[index][1] == data->localization[1])
			close_game(data);
	}
}
