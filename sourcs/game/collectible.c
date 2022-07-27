/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:07:02 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:42:27 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*collectible(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	if (i <= data->itens.collectible)
	{
		i++;
		if (i == data->itens.collectible)
			j = i;
		return (data->esfera);
	}
	else
	{
		j--;
		if (j < 0)
			i = 0;
		return (data->esfera1);
	}
	return (NULL);
}
