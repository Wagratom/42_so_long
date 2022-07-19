/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:20 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 16:42:21 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	find_exit(t_data *data)
{
	int i;
	int y;
	int x;

	y = -1;
	i = -1;
	while(data->layout[++y])
	{
		x = -1;
		while(data->layout[y][++x])
		{
			if (data->layout[y][x])
			{
				data->exit[++i] = malloc(sizeof(char) * 3);
				data->exit[i][0] = x;
				data->exit[i][1] = y;
				data->exit[i][2] = '\0';
			}
		}
	}
	data->exit[++i] = NULL;
}