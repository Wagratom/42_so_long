/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verific_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:17:46 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/08 17:48:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verific_dead(t_data *data)
{
	int	index;

	index = -1;
	while (data->enemies[++index])
	{
		if (data->enemies[index][0] == data->localization[0] &&
			data->enemies[index][1] == data->localization[1])
			close_game(data);
	}
}
