/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 01:54:04 by hkchikec          #+#    #+#             */
/*   Updated: 2020/01/04 06:07:11 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_point *point)
{
	if (key == 126)
		(point->shift_y -= 10);
	if (key == 125)
		(point->shift_y += 10);
	if (key == 124)
		(point->shift_x += 10);
	if (key == 123)
		(point->shift_x -= 10);
	if (key == 2)
		(point->shift_z -= 1);
	if (key == 32)
		(point->shift_z += 1);
}

int		bonus(int key, t_point *point)
{
	move(key, point);
	if (key == 69)
		(point->zoom += 1);
	if (key == 78)
		(point->zoom -= 1);
	if (key == 9)
		(point->shift_project = 1);
	if (key == 8)
		(point->shift_project = 0);
	if (key == 49)
		(point->colorize += 50);
	if (key == 53)
	{
		free(point->mlx_ptr);
		free(point->win_ptr);
		exit(0);
	}
	if (key == 15)
		init_var(point);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	draw(point);
	return (0);
}

void	drawrect(t_point *w, int fi, int fj, int cl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < fj)
	{
		i = 0;
		while (i < fi)
		{
			mlx_pixel_put(w->mlx_ptr, w->win_ptr, i, j, cl);
			i++;
		}
		j++;
	}
}

void	drawmenu(t_point *w)
{
	drawrect(w, 322, 800, 0x0E0E0E);
	drawrect(w, 322, 100, 0x323232);
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		322 / 2 - 40, 40, 0xFFFFFF, "Fdf Menu");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 140, 0xECECEC, "Arrows  : Move in The Map.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 240, 0xECECEC, "+ / -   : Zoom In / Out.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 290, 0xECECEC, "U / D   : In/Decrease Z Value.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 340, 0xECECEC, "C / V   : Switch Projections");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 440, 0xECECEC, "[space] : Change Color.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 490, 0xECECEC, "R       : Reset.");
	mlx_string_put(w->mlx_ptr, w->win_ptr,\
		20, 390, 0xECECEC, "ESC     : Exit");
}
