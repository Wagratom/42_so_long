/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:59:41 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 23:16:30 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init_aux(t_data *data);

void	data_init(t_data *data)
{
	int	wid;
	int	hei;
	int	x;
	int	y;

	x = data->itens.size_x * 44;
	y = data->itens.size_y * 58;
	data->direcion = 0;
	data->mlx = mlx_init();
	data->background = mlx_xpm_file_to_image(data->mlx, BACKGROUND, &wid, &hei);
	data->end = mlx_xpm_file_to_image(data->mlx, END, &wid, &hei);
	data->win = mlx_new_window(data->mlx, x, y, "So_long");
	data->wall = mlx_xpm_file_to_image(data->mlx, CLOUD, &wid, &hei);
	data->g_init = mlx_xpm_file_to_image(data->mlx, G_INIT, &wid, &hei);
	data->g_left = mlx_xpm_file_to_image(data->mlx, G_LEFT, &wid, &hei);
	data->g_right = mlx_xpm_file_to_image(data->mlx, G_RIGHT, &wid, &hei);
	data->k_init = mlx_xpm_file_to_image(data->mlx, K_INIT, &wid, &hei);
	data->k_up = mlx_xpm_file_to_image(data->mlx, K_UP, &wid, &hei);
	data->k_left = mlx_xpm_file_to_image(data->mlx, K_LEFT, &wid, &hei);
	data->k_down = mlx_xpm_file_to_image(data->mlx, K_DOWN, &wid, &hei);
	data->k_right = mlx_xpm_file_to_image(data->mlx, K_RIGHT, &wid, &hei);
	data->esfera = mlx_xpm_file_to_image(data->mlx, ESFERA, &wid, &hei);
	data->esfera1 = mlx_xpm_file_to_image(data->mlx, ESFERA1, &wid, &hei);
	data_init_aux(data);
}

void	data_init_aux(t_data *data)
{
	int	wid;
	int	hei;

	data->portal = mlx_xpm_file_to_image(data->mlx, PORTAL, &wid, &hei);
	data->portal1 = mlx_xpm_file_to_image(data->mlx, PORTAL1, &wid, &hei);
	data->zero = mlx_xpm_file_to_image(data->mlx, ZERO, &wid, &hei);
	data->one = mlx_xpm_file_to_image(data->mlx, ONE, &wid, &hei);
	data->two = mlx_xpm_file_to_image(data->mlx, TWO, &wid, &hei);
	data->three = mlx_xpm_file_to_image(data->mlx, THREE, &wid, &hei);
	data->four = mlx_xpm_file_to_image(data->mlx, FOUR, &wid, &hei);
	data->five = mlx_xpm_file_to_image(data->mlx, FIVE, &wid, &hei);
	data->six = mlx_xpm_file_to_image(data->mlx, SIX, &wid, &hei);
	data->seven = mlx_xpm_file_to_image(data->mlx, SEVEN, &wid, &hei);
	data->eight = mlx_xpm_file_to_image(data->mlx, EIGHT, &wid, &hei);
	data->none = mlx_xpm_file_to_image(data->mlx, NONE, &wid, &hei);
	data->movements = 0;
}
