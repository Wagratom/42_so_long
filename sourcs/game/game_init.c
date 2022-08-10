/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:57:47 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/10 21:13:19 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_init(t_data *data)
{
	data_init(data);
	draw_map(data);
	draw_movies(data);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, &filter_key, data);
	mlx_hook(data->win, EXIT, 0, &close_game, data);
	mlx_hook(data->win, FOCUS, 1L << 21, &draw_map, data);
	mlx_expose_hook(data->win, &draw_map, data);
	mlx_loop_hook(data->mlx, &draw_map_time, data);
	mlx_loop(data->mlx);
}
