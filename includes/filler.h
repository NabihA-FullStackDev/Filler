/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:43:36 by nabih             #+#    #+#             */
/*   Updated: 2019/11/10 01:02:06 by nabih            ###   ########.fr       */
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

typedef struct		s_resolution
{
	unsigned int	i;
	char			c;
	char			op;
	int				contact;
	int				new_pts;
}					t_resolution;

typedef struct		s_piece
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	nb;
	t_solve			*vec_piec;
}					t_piece;

typedef struct		s_player
{
	char			*line;
	int				order;
	int				space;

	char			**plateau;
	char			**cp_plat;
	char			**value;
	int				x_plat;
	int				y_plat;
	unsigned int	xy_plat;

	t_piece			s_piec;
	char			**piece;
	int				x_piec;
	int				y_piec;
	unsigned int	xy_piec;

	int				y_start;
	int				x_start;
	int				y_op_st;
	int				x_op_st;

	int				flag;
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

//int				check_contact(t_player *p, int x, int y);
int				check_contact(t_player *p, t_piece *pi, int x, int y);

int				solve_xplus_yplus(t_solve *s, t_player *p, int x, int y);
int				solve_xplus_yminus(t_solve *s, t_player *p, int x, int y);
int				solve_xminus_yplus(t_solve *s, t_player *p, int x, int y);
int				solve_xminus_yminus(t_solve *s, t_player *p, int x, int y);

char			**cpy_plateau(char **dst, const char **src, unsigned int max);
void			update_tab_value(char ***val, int max, char start, char new_c);
void			fill_value(char ***val, int max);
void			tab_bzero(char ***tab, int size);

/* TEST A SUPPRIMER */
void			print_tab_for_test(char **tab, int size);

#endif
