/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atualize_host.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:49:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/28 00:36:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_down(t_data *data, int index);
void	move_right(t_data *data, int index);
void	move_up(t_data *data, int index);
void	move_left(t_data *data, int index);

void	move_down(t_data *data, int index)
{
	int	x;
	int	y;

	x = data->enemies[index][0];
	y = data->enemies[index][1];
	if (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'P')
	{
		if (data->map[y + 1][x] == 'P')
			close_game(data);
		data->enemies[index][1] = y + 1;
	}
	else
	{
		data->enemies[index][2] = 2;
		move_right(data, index);
	}
}

void	move_right(t_data *data, int index)
{
	int	x;
	int	y;

	x = data->enemies[index][0];
	y = data->enemies[index][1];
	if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P')
	{
		if (data->map[y][x + 1] == 'P')
			close_game(data);
		data->enemies[index][0] = x + 1;
	}
	else
	{
		data->enemies[index][2] = 3;
		move_up(data, index);
	}
}

void	move_up(t_data *data, int index)
{
	int	x;
	int	y;

	x = data->enemies[index][0];
	y = data->enemies[index][1];
	if (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'P')
	{
		if (data->map[y - 1][x] == 'P')
			close_game(data);
		data->enemies[index][1] = y - 1;
	}
	else
	{
		data->enemies[index][2] = 4;
		move_left(data, index);
	}
}

void	move_left(t_data *data, int index)
{
	int	x;
	int	y;

	x = data->enemies[index][0];
	y = data->enemies[index][1];
	if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
	{
		if (data->map[y][x - 1] == 'P')
			close_game(data);
		data->enemies[index][0] = x - 1;
	}
	else
		data->enemies[index][2] = 1;
}

void	atualize_host(t_data *data)
{
	int	y;

	y = -1;
	while (data->enemies[++y])
	{
		if (data->enemies[y][2] == 0)
		{
			data->enemies[y][2] = 1;
			move_down(data, y);
		}
		else if (data->enemies[y][2] == 1)
			move_down(data, y);
		else if (data->enemies[y][2] == 2)
			move_right(data, y);
		else if (data->enemies[y][2] == 3)
			move_up(data, y);
		else if (data->enemies[y][2] == 4)
			move_left(data, y);
	}
}
