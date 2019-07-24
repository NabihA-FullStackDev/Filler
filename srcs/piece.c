/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:29:01 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 12:29:08 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_piece_size(t_player *p)
{
	int		size;

	if ((size = get_next_line(0, &(p->line))) == -1)
		ft_putstr("Bad piece info 1\n");
	else
	{
		p->piece = ft_strsplit(p->line, ' ');
		if ((size = get_tab_size(p->piece)) == 3
			&& ft_strncmp(p->line, "Piece", 5) == 0)
		{
			p->y_piec = ((p->piece)[1] != NULL) ?
				ft_atoi((p->piece)[1]) : 0;
			p->x_piec = ((p->piece)[2] != NULL) ?
				ft_atoi((p->piece)[2]) : 0;
		}
		free_str_tab(&(p->piece), size);
		if (p->y_piec == 0 || p->x_piec == 0)
		{
			ft_putstr("Bad piece info 2\n");
			free_str(&(p->line));
			return (-1);
		}
	}
	free_str(&(p->line));
	return ((size == 3) ? 0 : -1);
}

void			tab_bzero(char ***tab, int size);

int				get_piece(t_player *p)
{
	int		y;

	y = 0;
	if ((p->piece = (char**)malloc(sizeof(char*) * (p->y_piec /* + 1 */))) == NULL)
		return (-1);
	while (y < p->y_piec && get_next_line(0, &(p->line)) != -1)
	{
		if (((p->piece)[y] = (char*)malloc(sizeof(char) \
										* (ft_strlen(p->line) + 1))) == NULL)
			return (-1);
		ft_strcpy((p->piece)[y], p->line);
		free_str(&(p->line));
		y++;
	}
	free_str(&(p->line));
	return (0);
}
