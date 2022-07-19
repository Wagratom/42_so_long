/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:13:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 15:05:07 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	game_init(t_data *data)
{
	data_init(data);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, filter_key, data);
	mlx_hook(data->win, EXIT, 0, close, data);
	mlx_loop_hook(data->mlx, draw_map, data);
	mlx_loop(data->mlx);
	return (0);
}
