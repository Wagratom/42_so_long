/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:42:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:51:56 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_movies(t_data *data)
{
	int	temp;
	int	temp1;
	int	position;

	position = numb_house(data->movements, 10);
	temp = data->movements;
	while (temp)
	{
		position--;
		temp1 = temp % 10;
		draw_movies_aux(data, temp1, position);
		temp /= 10;
	}
}

void	draw_movies_aux(t_data *data, int nb, int position)
{
	position *= 44;
	mlx_put_image_to_window(data->mlx, data->win, data->zero, position, 0);
	if (nb == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->zero, position, 0);
	else if (nb == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->one, position, 0);
	else if (nb == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->two, position, 0);
	else if (nb == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->three, position, 0);
	else if (nb == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->four, position, 0);
	else if (nb == 5)
		mlx_put_image_to_window(data->mlx, data->win, data->five, position, 0);
	else if (nb == 6)
		mlx_put_image_to_window(data->mlx, data->win, data->six, position, 0);
	else if (nb == 7)
		mlx_put_image_to_window(data->mlx, data->win, data->seven, position, 0);
	else if (nb == 8)
		mlx_put_image_to_window(data->mlx, data->win, data->eight, position, 0);
	else if (nb == 9)
		mlx_put_image_to_window(data->mlx, data->win, data->none, position, 0);
}
