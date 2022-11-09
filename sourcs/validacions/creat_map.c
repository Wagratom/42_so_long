/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:31:03 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/09 16:57:32 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	creat_map_aux(int fd, t_data *data);

static int	valid_colun(char **map, int x, int y)
{
	int	i;

	i = -1;
	while (map[0][++i] && map[0] && i < x)
	{
		if (map[0][i] != '1' || i > 26)
		{
			if (map[0][i] != '1')
				write(2, "Error: fist colun invalid\n", 27);
			else
				write(2, "Error: invalid map width\n", 26);
			return (del_map(map));
		}
	}
	i = -1;
	while (map[y][++i])
	{
		if (map[y][i] != '1')
		{
			write(2, "Error: last colun invalid\n", 27);
			return (del_map(map));
		}
	}
	return (0);
}

static int	valid_line(char **map, int x, int y)
{
	int	i;

	i = -1;
	while (i++ < y && map[i][0])
	{
		if (map[i][0] != '1' || i > 10)
		{
			if (map[i][0] != '1')
				write(2, "Error: fist line invalid\n", 25);
			else
				write(2, "Error: invalid map height\n", 26);
			return (del_map(map));
		}
	}
	i = -1;
	while (i++ < y && map[i][x])
	{
		if (map[i][x] != '1')
		{
			write(2, "Error: last line invalid\n", 25);
			return (del_map(map));
		}
	}
	return (0);
}

//*******************************
//				init			*
//*******************************

int	creat_map(int fd, t_data *data)
{
	int	x;
	int	y;

	x = data->itens.size_x - 1;
	y = data->itens.size_y - 1;
	creat_map_aux(fd, data);
	if (valid_colun(data->map, x, y) || valid_line(data->map, x, y))
		return (write(1, "Error creat map\n", 16));
	close(fd);
	return (0);
}

static int	creat_map_aux(int fd, t_data *data)
{
	int	size_map;
	int	i;

	i = -1;
	size_map = data->itens.size_y + 1;
	data->map = (char **)malloc(sizeof(char *) * size_map);
	while (++i <= data->itens.size_y)
		data->map[i] = get_next_line(fd);
	return (0);
}
