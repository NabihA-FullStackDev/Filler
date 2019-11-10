/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:52:02 by nabih             #+#    #+#             */
/*   Updated: 2019/11/10 02:22:16 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			init_player_vars(t_player *p)
{
	p->line = NULL;
	p->order = 0;
	p->plateau = NULL;
	p->cp_plat = NULL;
	p->value = NULL;
	p->x_plat = 0;
	p->y_plat = 0;
	p->xy_plat = 0;
	p->piece = NULL;
	p->x_piec = 0;
	p->y_piec = 0;
	p->xy_piec = 0;
	p->x_start = -1;
	p->y_start = -1;
	p->x_op_st = -1;
	p->y_op_st = -1;
	p->flag = 0;
}

int				get_order_num(t_player *p)
{
	if (get_next_line(0, &(p->line)) == -1)
	{
		ft_putstr("Bad player info\n");
		free_str(&(p->line));
		return (-1);
	}
	if (ft_strncmp(p->line, "$$$ exec p1 :", 13) == 0)
		p->order = 1;
	else if (ft_strncmp(p->line, "$$$ exec p2 :", 13) == 0)
		p->order = 2;
	else
		ft_putstr("Bad player info\n");
	free_str(&(p->line));
	return ((p->order == 1 || p->order == 2) ? 0 : -1);
}
