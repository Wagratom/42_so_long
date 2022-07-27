/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:32:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/28 00:10:48 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	del_img_map(t_data *data);
void	del_img_numbers(t_data *data);

void	del_array(int **array)
{
	int	y;

	y = -1;
	while (array[++y])
		free(array[y]);
	free(array);
}

int	del_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
	return (1);
}

int	close_game(t_data *data)
{
	del_array(data->enemies);
	del_array(data->exits);
	del_map(data->map);
	del_img_map(data);
	del_img_numbers(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	del_img_map(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->end);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->g_init);
	mlx_destroy_image(data->mlx, data->g_left);
	mlx_destroy_image(data->mlx, data->g_right);
	mlx_destroy_image(data->mlx, data->k_init);
	mlx_destroy_image(data->mlx, data->k_up);
	mlx_destroy_image(data->mlx, data->k_left);
	mlx_destroy_image(data->mlx, data->k_down);
	mlx_destroy_image(data->mlx, data->k_right);
	mlx_destroy_image(data->mlx, data->esfera);
	mlx_destroy_image(data->mlx, data->esfera1);
	mlx_destroy_image(data->mlx, data->portal);
	mlx_destroy_image(data->mlx, data->portal1);
}

void	del_img_numbers(t_data *data)
{
	mlx_destroy_image(data->mlx, data->zero);
	mlx_destroy_image(data->mlx, data->one);
	mlx_destroy_image(data->mlx, data->two);
	mlx_destroy_image(data->mlx, data->three);
	mlx_destroy_image(data->mlx, data->four);
	mlx_destroy_image(data->mlx, data->five);
	mlx_destroy_image(data->mlx, data->six);
	mlx_destroy_image(data->mlx, data->seven);
	mlx_destroy_image(data->mlx, data->eight);
	mlx_destroy_image(data->mlx, data->none);
}
