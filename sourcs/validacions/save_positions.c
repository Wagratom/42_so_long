/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:38:04 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/08 20:42:37 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	save_exit(t_data *data, int x, int y)
{
	static int	index = 0;
	static int	portal = 0;

	data->exits[index] = (int *)malloc(sizeof(int) * 3);
	data->exits[index][0] = x;
	data->exits[index][1] = y;
	data->exits[index][2] = portal;
	if (portal == 0)
		portal = 1;
	else
		portal = 0;
	return (++index);
}

static int	save_enemy(t_data *data, int x, int y)
{
	static int	index = 0;
	static int	direcion = 1;

	if (direcion == 3)
		direcion = 0;
	data->enemies[index] = (int *)malloc(sizeof(int) * 3);
	data->enemies[index][0] = x;
	data->enemies[index][1] = y;
	data->enemies[index][2] = direcion;
	data->map[y][x] = '0';
	direcion++;
	return (++index);
}

void	save_personage(t_data *data, int x, int y)
{
	data->localization[0] = x;
	data->localization[1] = y;
}

void	save_positions(t_data *data)
{
	int	y;
	int	x;
	int	numb_exits;
	int	numb_enemys;

	data->exits = (int **)malloc(sizeof(int *) * (data->itens.exit + 1));
	data->enemies = (int **)malloc(sizeof(int *) * (data->itens.enemies + 1));
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'E')
				numb_exits = save_exit(data, x, y);
			else if (data->map[y][x] == 'A')
				numb_enemys = save_enemy(data, x, y);
			else if (data->map[y][x] == 'P')
				save_personage(data, x, y);
		}
	}
	data->exits[numb_exits] = NULL;
	data->enemies[numb_enemys] = NULL;
}
