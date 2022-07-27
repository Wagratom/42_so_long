/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:31:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/26 22:53:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		if (valid_map(argv[1], &data))
			return (1);
		save_positions(&data);
		game_init(&data);
	}
	else
		return (write(1, "Invalid numb of arguments\n", 26));
	return (0);
}
