/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:33:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 04:53:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	valid_colun(t_data *data, int y);
static int	valid_line(t_data *data, int x);
static int	find_localization(t_data *data);

int	valid_wall(t_data *data)
{
	if (valid_colun(data, data->size_y - 1))
		return (1);
	if (valid_line(data, data->size_x - 1))
		return (1);
	find_localization(data);
	return (0);
}

static int	valid_colun(t_data *data, int y)
{
	int size_x;
	int	x;

	x = -1;
	size_x = data->size_x;
	while (data->layout[0][++x] && x < size_x)
	{
		if (data->layout[0][x] != '1')
			return (printf("Error: fist colun invalid\n"));
	}
	x = -1;
	while (data->layout[y][++x])
	{
		if (data->layout[y][x] != '1')
			return (printf("Error: last colun invalid\n"));
	}
	return (0);
}

static int	valid_line(t_data *data, int x)
{
	int y;
	int size_y;

	size_y = data->size_y - 1;
	y = -1;
	while (y++ < size_y)
	{
		if (data->layout[y][0] != '1')
			return (printf("Error: fist line invalid\n"));
	}
	y = -1;
	while (y++ < size_y)
	{
		if (data->layout[y][x] != '1')
			return (printf("Error: last line invalid\n"));
	}
	return (0);
}

static int	find_localization(t_data *data)
{
	int	y;
	int x;

	y = -1;
	data->exit = 0;
	while (data->layout[++y])
	{
		x = -1;
		while (data->layout[y][++x])
		{
			if (data->layout[y][x] == 'P')
			{
				data->position[0] = x;
				data->position[1] = y;
			}
		}
	}
	return(0);
}