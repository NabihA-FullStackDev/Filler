/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:39:30 by nabih             #+#    #+#             */
/*   Updated: 2019/11/12 13:39:00 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			free_str(char **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void			free_str_tab(char ***ptr, int size)
{
	int			i;

	i = 0;
	if (ptr != NULL && *ptr != NULL)
	{
		while (i < size && *ptr != NULL)
		{
			free_str(&((*ptr)[i]));
			i++;
		}
		free(*ptr);
		*ptr = NULL;
	}
}
