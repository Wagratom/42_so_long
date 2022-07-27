/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:12:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:24:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	personage(t_data *data, int x, int y)
{
	static int	i = 1;

	if (i == 1)
		i = -1;
	else if (i == -1)
		i = 1;
	if (data->direcion == 0)
		put_img(data, data->g_init, x, y + i);
	else if (data->direcion == 2)
		put_img(data, data->g_left, x, y + i);
	else
		put_img(data, data->g_right, x, y + i);
}
