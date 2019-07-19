/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:29:53 by naali             #+#    #+#             */
/*   Updated: 2019/07/19 10:21:07 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		first_get_everything(t_player *p)
{
	if (get_order_num(p) == -1)
		return (-1);
	if (get_board_size(p) == -1)
		return (-1);
	if (get_first_board(p) == -1)
		return (-1);
	/* if (get_piece_size(p) == -1) */
	/* 	return (-1); */
	/* if (get_piece(p) == -1) */
	/* 	return (-1); */
	return (0);
}

int				main(void)
{
	t_player	p;

	init_player_vars(&p);
	if (first_get_everything(&p) == -1)
		return (-1);
	printf("8 2\n");
	return (0);
}
