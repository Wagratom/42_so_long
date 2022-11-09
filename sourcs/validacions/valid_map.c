/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:33:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/09 16:56:20 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(char *file, t_data *data)
{
	int	fd;

	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 4))
		return (write(2, "Error: invalid extecion\n", 24));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Erro: unable to read the file\n", 30));
	if (valid_chars(fd, &(data->itens)))
		return (1);
	if (creat_map(open(file, O_RDONLY), data))
		return (1);
	return (0);
}
