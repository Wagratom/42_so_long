/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:26:27 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 15:51:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	up(t_data *data)
{
	int x;
	int y;

	x = data->position[0];
	y = data->position[1];
	if (data->layout[y - 1][x] != '1')
	{
		if (data->layout[y - 1][x] == 'C')
			data->collectible--;
		data->layout[y][x] = '0';
		data->layout[--y][x] = 'P';
		data->position[1] = y;
	}
	printf("mov = %d\n", (data->count_mov += 1));
}

void	left(t_data *data)
{
	int x;
	int y;

	x = data->position[0];
	y = data->position[1];
	if (data->layout[y][x - 1] != '1')
	{
		if (data->layout[y][x - 1] == 'C')
			data->collectible--;
		data->layout[y][x] = '0';
		data->layout[y][--x] = 'P';
		data->position[0] = x;
	}
	y - 1;
	printf("mov = %d\n", (data->count_mov += 1));
	data->direcion = 2;
}

void	down(t_data *data)
{
	int x;
	int y;

	x = data->position[0];
	y = data->position[1];
	if (data->layout[y + 1][x] != '1')
	{
		if (data->layout[y + 1][x] == 'C')
			data->collectible--;
		data->layout[y][x] = '0';
		data->layout[++y][x] = 'P';
		data->position[1] = y;
	}
	printf("mov = %d\n", (data->count_mov += 1));
}

void	rigth(t_data *data)
{
	int x;
	int y;

	x = data->position[0];
	y = data->position[1];
	
	if (data->layout[y][x + 1] != '1')
	{
		if (data->layout[y][x + 1] == 'C')
			data->collectible--;
		data->layout[y][x] = '0';
		data->layout[y][++x] = 'P';
		data->position[0] = x;
	}
	printf("mov = %d\n", (data->count_mov += 1));
	data->direcion = 4;
}

int filter_key(int key, t_data *data)
{
	if (key == 65307)
		exit(1);
	else if (key == KEY_W)
		up(data);
	else if (key == KEY_A)
		left(data);
	else if (key == KEY_S)
		down(data);
	else if (key == KEY_D)
		rigth(data);
	return (0);
}