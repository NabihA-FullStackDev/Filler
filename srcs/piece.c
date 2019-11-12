/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:29:01 by nabih             #+#    #+#             */
/*   Updated: 2019/11/12 13:10:31 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_piece_size(t_player *p)
{
	int		size;

	if ((size = get_next_line(0, &(p->line))) == -1)
		ft_putstr_fd("Bad piece info 1\n", 2);
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
		free_str_tab(&(p->piece), size + 1);
		if (p->y_piec == 0 || p->x_piec == 0)
		{
			ft_putstr_fd("Bad piece info 2\n", 2);
			free_str(&(p->line));
			return (-1);
		}
	}
	free_str(&(p->line));
	return ((size == 3) ? 0 : -1);
}

int				fill_vectors(t_player *p, char **piece, int nb)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	y = p->s_piec.y;
	x = -1;
	if ((p->s_piec.vec_piec = (t_solve*)malloc(sizeof(t_solve) * nb)) == NULL)
		return (-1);
	while (y < p->y_piec)
	{
		x = (x == -1) ? p->s_piec.x : 0;
		while (x < p->x_piec)
		{
			if (piece[y][x] == '*')
			{
				(p->s_piec.vec_piec)[i].x = (i == 0) ? 0 : x - p->s_piec.x;
				(p->s_piec.vec_piec)[i].y = (i == 0) ? 0 : y - p->s_piec.y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				init_piece_struct(t_player *p, char **piece)
{
	int			x;
	int			y;
	int			flg;

	y = 0;
	flg = 0;
	p->s_piec.nb = 0;
	p->s_piec.vec_piec = NULL;
	while (y < p->y_piec)
	{
		x = 0;
		while (piece[y][x] != '\0')
		{
			if (piece[y][x] == '*' && flg == 0)
			{
				p->s_piec.x = x;
				p->s_piec.y = y;
				flg = 1;
			}
			(piece[y][x] == '*') ? p->s_piec.nb++ : 0;
			x++;
		}
		y++;
	}
	return (fill_vectors(p, piece, p->s_piec.nb));
}

int				get_piece(t_player *p)
{
	int		y;

	y = 0;
	if ((p->piece = (char**)malloc(sizeof(char*) * (p->y_piec))) == NULL)
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
	if (init_piece_struct(p, p->piece) == -1)
		return (-1);
	return (0);
}
