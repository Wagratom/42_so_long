/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:48:59 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/19 16:45:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char *argv[])
{
	t_data	data;
	int y = -1;

	printf("dei init\n");
	if (argc == 2 && !valid_map(argv[1], &data))
	{
		find_exit(&data);
		while (data.exit[++y])
		{
			printf("exit[%d], X = %d\n", y, data.exit[y][0]);
			printf("exit[%d], Y = %d\n", y, data.exit[y][1]);
		}
		game_init(&data);
	}
	else
		return (printf("Invalid number of arguments\n"));
	return (0);
}