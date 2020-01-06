/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:16:06 by hkchikec          #+#    #+#             */
/*   Updated: 2020/01/04 01:57:41 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/*
** Macros
*/

# define MAX(a, b) (a > b ? a : b)
# define ABS(a) ((a < 0) ? -a : a)
# define DEFAULT_COLOR 16777215

/*
** Structures
*/

typedef struct	s_bresnhelp
{
	int			col;
	int			row;
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
}				t_bresnhelp;

typedef struct	s_readhelp
{
	int			col;
	int			row;
	int			j;
	int			i;
}				t_readhelp;

typedef	struct	s_coords
{
	int			z_val;
	int			color;
	int			col_snif;
}				t_coords;

typedef struct	s_point
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*mlx_menu;
	void		*win_ptr;
	void		*menu_ptr;
	double		zoom;
	int			shift_x;
	int			shift_y;
	double		shift_z;
	int			shift_project;
	int			colorize;
	t_coords	**coords;
}				t_point;

/*
** Read File / map
*/

void			read_map(t_point *points, char *path);
void			read_file(int fd, char *line, t_point *points,\
				char **splited_line);

/*
** Count lines of map and lenght
*/

int				count_lines(char *path);
int				count_lenght(char *path);

/*
** Count lines of map and lenght
*/

int				split_col(t_point *point, char *str, int col, int row);

/*
** Free double pointer
*/

void			free_2d(char ***tmp);

/*
** Hexadecimal to Decimal
*/

void			htoi_cond(char *hexval, int i, int *dec_val, int *base);
int				ft_htoi(char *hexval);

/*
** Bresnham put pixel and bresnhanm theory
*/

void			bresnham_pp(t_bresnhelp bres, t_point *point);
void			bresenham(t_bresnhelp bres, t_point *point);

/*
** Drawing lines
*/

void			draw_helper(t_bresnhelp coord, t_point *point);
void			draw(t_point *point);

/*
** Isometric projection
*/

void			iso(float *x, float *y, int z);

/*
** initialization of vars using in program
*/

void			init_var(t_point *point);

void			parser(char **splited_line, t_point *points, t_readhelp coord);

/*
** move map using keyboard keys
*/

void			move(int key, t_point *point);

/*
** contains || Zoom || Projection Type || Changing colors || ESC to exit
*/

int				bonus(int key, t_point *point);

/*
** Manage colors
*/

void			color_changing(t_bresnhelp bres, t_point *point);
void			return_erro(void);
void			drawmenu(t_point *w);
void			drawrect(t_point *w, int fi, int fj, int cl);

#endif
