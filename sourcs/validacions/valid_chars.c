/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:29:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/09 16:57:08 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_line(t_itens *itens, char *line);
static int	verific_items(t_itens *itens, char c);

static void	init_itens(t_itens *itens)
{
	itens->collectible = 0;
	itens->position = 0;
	itens->enemies = 0;
	itens->exit = 0;
	itens->size_x = 0;
	itens->size_y = 0;
}

static int	valid_itens(t_itens	*itens)
{
	if (itens->collectible == 0)
		return (write(2, "invalid numb of collectible\n", 26));
	else if (itens->exit == 0)
		return (write(2, "the map not has exit\n", 22));
	else if (itens->position == 0)
		return (write(2, "the map does not have a starting position\n", 43));
	return (0);
}

//***************************
//			init			*
//***************************

int	valid_chars(int fd, t_itens	*itens)
{
	char	*line;

	init_itens(itens);
	line = get_next_line(fd);
	itens->size_x = ft_strlen(line) - 1;
	while (line)
	{
		itens->size_y += 1;
		if (check_line(itens, line))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	if (valid_itens(itens))
		return (1);
	close(fd);
	return (0);
}

static int	check_line(t_itens *itens, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n' && i != itens->size_x)
			return (write(1, "Error: Invalid break line\n", 26));
		if (!ft_strchr("01PCEA\n", line[i]))
			return (write(1, "Erro: Invalid argument\n", 23));
		if (ft_strchr("PCEA", line[i]))
		{
			if (verific_items(itens, line[i]))
				return (1);
		}
	}
	return (0);
}

static int	verific_items(t_itens *itens, char c)
{
	if (c == 'P')
	{
		itens->position += 1;
		if (itens->position > 1)
			return (write(2, "Error: there are two starting position\n", 39));
	}
	else if (c == 'C')
		itens->collectible += 1;
	else if (c == 'E')
		itens->exit += 1;
	else if (c == 'A')
		itens->enemies += 1;
	return (0);
}
