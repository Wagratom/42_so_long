/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:58:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/14 19:03:31 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_ptr(char **bloco1, char **bloco2)
{
	if (bloco1)
	{
		free((*bloco1));
		*bloco1 = NULL;
	}
	if (bloco2)
	{
		free((*bloco2));
		*bloco2 = NULL;
	}
	return (NULL);
}
