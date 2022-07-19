/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:53:41 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/17 23:53:11 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	my_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(1);
}