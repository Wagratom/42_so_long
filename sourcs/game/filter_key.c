/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:28:19 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 23:13:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	up(t_data *data)
{
	int	x;
	int	y;

	x = data->localization[0];
	y = data->localization[1];
	if (data->map[y - 1][x] != '1')
	{
		if (data->map[y - 1][x] == 'A')
			close_game(data);
		if (data->map[y - 1][x] == 'C')
			data->itens.collectible--;
		data->map[y][x] = '0';
		data->map[--y][x] = 'P';
		data->localization[1] = y;
		data->movements += 1;
	}
	draw_map(data);
	draw_movies(data);
}

static void	left(t_data *data)
{
	int	x;
	int	y;

	x = data->localization[0];
	y = data->localization[1];
	if (data->map[y][x - 1] != '1')
	{
		if (data->map[y][x - 1] == 'A')
			close_game(data);
		if (data->map[y][x - 1] == 'C')
			data->itens.collectible--;
		data->map[y][x] = '0';
		data->map[y][--x] = 'P';
		data->localization[0] = x;
		data->movements += 1;
	}
	data->direcion = 2;
	draw_map(data);
	draw_movies(data);
}

static void	down(t_data *data)
{
	int	x;
	int	y;

	x = data->localization[0];
	y = data->localization[1];
	if (data->map[y + 1][x] != '1')
	{
		if (data->map[y + 1][x] == 'A')
			close_game(data);
		if (data->map[y + 1][x] == 'C')
			data->itens.collectible--;
		data->map[y][x] = '0';
		data->map[++y][x] = 'P';
		data->localization[1] = y;
		data->movements += 1;
	}
	draw_map(data);
	draw_movies(data);
}

static void	right(t_data *data)
{
	int	x;
	int	y;

	x = data->localization[0];
	y = data->localization[1];
	if (data->map[y][x + 1] != '1')
	{
		if (data->map[y][x + 1] == 'A')
			close_game(data);
		if (data->map[y][x + 1] == 'C')
			data->itens.collectible--;
		data->map[y][x] = '0';
		data->map[y][++x] = 'P';
		data->localization[0] = x;
		data->movements += 1;
	}
	data->direcion = 4;
	draw_map(data);
	draw_movies(data);
}

int	filter_key(int key, t_data *data)
{
	if (key == KEY_W)
		up(data);
	else if (key == KEY_A)
		left(data);
	else if (key == KEY_S)
		down(data);
	else if (key == KEY_D)
		right(data);
	else if (key == 65307)
		close_game(data);
	return (0);
}
