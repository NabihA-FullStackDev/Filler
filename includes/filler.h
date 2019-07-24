/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:43:36 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 12:25:09 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FILLER_H
# define	FILLER_H

# include <includes.h>

# define XPLUS 2
# define XMOIN 4
# define YPLUS 8
# define YMOIN 16

typedef struct		s_solve
{
	int			x;
	int			y;
}					t_solve;

typedef struct		s_player
{
	char			*line;
	int				order;
	int				space;
	char			**plateau;
	int				x_plat;
	int				y_plat;
	unsigned int	xy_plat;
	char			**piece;
	int				x_piec;
	int				y_piec;
	unsigned int	xy_piec;
	int				y_start;
	int				x_start;
	int				y_op_st;
	int				x_op_st;
}					t_player;

/* Structure Player */
void			init_player_vars(t_player *p);
void			free_str(char **ptr);
void			free_str_tab(char ***ptr, int size);
int				get_order_num(t_player *p);
int				get_space(t_player *p);
int				get_start(t_player *p);

/* READ Plateau et Piece */
int				get_tab_size(char **tab);

int				get_board_size(t_player *p);
int				get_board(t_player *p);

int				get_piece_size(t_player *p);
int				get_piece(t_player *p);

/* Resolution du Tableau */
int				solve(t_player *p);
void			print_answer(int y, int x);
char			get_char_player(t_player *p);
int				choose_solver(t_solve *s, t_player *p, int mask);

#endif
