/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:29:53 by naali             #+#    #+#             */
/*   Updated: 2019/11/10 04:09:29 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		get_everything(t_player *p)
{
	if (get_board_size(p) == -1)
		return (-1);
	if (get_board(p) == -1)
		return (-1);
	if (get_piece_size(p) == -1)
		return (-1);
	if (get_piece(p) == -1)
		return (-1);
	return (0);
}

static int		first_call(t_player *p)
{
	int			stop;

	stop = 0;
	if ((stop = get_everything(p)) == -1)
		return (-1);
	if (get_space(p) == -1)
		return (-1);
	if (get_start(p) == -1)
		return (-1);
	stop = solve(p);
	free_str_tab(&(p->plateau), p->y_plat + 1);
	free_str_tab(&(p->piece), p->y_piec);
	return (0);
}

int				main(void)
{
	t_player	p;
	int			stop;

	stop = 0;
	init_player_vars(&p);
	if (get_order_num(&p) == -1)
		return (-1);
	stop = first_call(&p);
	(p.s_piec.vec_piec != NULL) ? free(p.s_piec.vec_piec) : 0;
	(p.s_piec.vec_piec != NULL) ? p.s_piec.vec_piec = NULL : 0;
	while (stop == 0 && get_everything(&p) == 0)
	{
		stop = solve(&p);
		free_str_tab(&(p.plateau), p.y_plat + 1);
		free_str_tab(&(p.piece), p.y_piec);
		(p.s_piec.vec_piec != NULL) ? free(p.s_piec.vec_piec) : 0;
		(p.s_piec.vec_piec != NULL) ? p.s_piec.vec_piec = NULL : 0;
	}
	free_str_tab(&(p.value), p.y_plat + 1);
	return (0);
}
