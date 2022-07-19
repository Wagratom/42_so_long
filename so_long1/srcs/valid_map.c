/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:15:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 16:47:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int			creat_map(t_map_data map_data, t_data *data, int fd);
int			check_map_aux(t_map_data *items, int fd);
static int	verific_char(t_map_data *items, char c);

int	verific_items(t_data *data, t_map_data items)
{
	if (items.collectible == 0)
		return (printf("Error: invalid number of collectible\n"));
	else if (items.exit == 0)
		return (printf("Error: the map has no exit\n"));
	else if(items.position == 0)
		return (printf("Error: the map does not have a starting position\n"));
	data->collectible = items.collectible;
	data->exit = malloc(sizeof(char *) * (items.exit  + 1));
	return (0);
}

int	valid_map(char *file, t_data *data)
{
	t_map_data	items;
	int			fd;

	items.collectible = 0;
	items.position = 0;
	items.exit = 0;
	items.size_y = 0;
	items.size_x = -1;
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 4))
		return (printf("Invalid extecion\n"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("Error opening file\n"));
	if (check_map_aux(&items, fd))
			return (1);
	if (verific_items(data, items))
		return (1);
	data->size_x = items.size_x;
	data->size_y = items.size_y;
	printf("X = %d\nY = %d\n",data->size_x, data->size_y);
	if (creat_map(items, data, open(file, O_RDONLY)))
		return (printf("Error creat mat\n"));

	return (0);
}

int check_map_aux(t_map_data *items, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	items->size_x += ft_strlen(line);
	while (line)
	{
		i = -1;
		items->size_y += 1;
		while (line[++i] && i < items->size_x)
		{
			if (line[i] == '\n')
				return (printf("Error: Invalid break line\n"));
			if (!ft_strchr("10PCEA", line[i]))
				return (printf("Error: The map has some invalid character\n"));
			if (line[i] == 'C' || line[i] == 'E' || line[i] == 'P')
			{
				if (verific_char(items, line[i]))
					return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
		if ((line && ft_strlen(line) - 1) == items->size_x)
			return (printf("Error: invalid map\n"));
	}
	close(fd);
	return (0);
}

static int	verific_char(t_map_data *items, char c)
{
	if (c == 'P')
	{
		items->position += 1;
		if (items->position > 1)
			return (printf("the map has more than one starting position\n"));
	}
	else if (c == 'C')
		items->collectible += 1;
	else
		items->exit += 1;
	return (0);
}

int	creat_map(t_map_data data_map, t_data *data, int fd)
{
	char	**map;
	int		i;

	i = -1;
	map = malloc(sizeof(char *) * (data_map.size_y + 1));
	while (data_map.size_y--)
		map[++i] = get_next_line(fd);
	map[++i] = NULL;
	data->layout = map;
	if (valid_wall(data))
		return (1);
	close(fd);
	return (0);
}
