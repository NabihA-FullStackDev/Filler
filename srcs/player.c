/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:52:02 by nabih             #+#    #+#             */
/*   Updated: 2019/07/19 09:14:23 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			init_player_vars(t_player *p)
{
	p->line = NULL;
	p->order = 0;
	p->plateau = NULL;
	p->x_plat = 0;
	p->y_plat = 0;
	p->piece = NULL;
	p->x_piec = 0;
	p->y_piec = 0;
}

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
		while (i < size)
		{
			free_str(&((*ptr)[i]));
			i++;
		}
		free(*ptr);
		*ptr = NULL;
	}
}

int				get_order_num(t_player *p)
{
	if (get_next_line(0, &(p->line)) == -1)
	{
		ft_putstr("Bad player info\n");
		free_str(&(p->line));
		return (-1);
	}
	if (ft_strcmp(p->line, "$$$ exec p1 : [./naali.filler]") == 0)
		p->order = 1;
	else if (ft_strcmp(p->line, "$$$ exec p2 : [./naali.filler]") == 0)
		p->order = 2;
	else
		ft_putstr("Bad player info\n");
	free_str(&(p->line));
	return ((p->order == 1 || p->order == 2) ? 0 : -1);
}
