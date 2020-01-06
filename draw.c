/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 05:27:09 by hkchikec          #+#    #+#             */
/*   Updated: 2020/01/04 05:48:35 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			bresnham_pp(t_bresnhelp bres, t_point *point)
{
	float		xs;
	float		ys;
	int			max;

	xs = bres.x1 - bres.x;
	ys = bres.y1 - bres.y;
	max = MAX(ABS(xs), ABS(ys));
	xs /= max;
	ys /= max;
	while ((int)(bres.x - bres.x1) || (int)(bres.y - bres.y1))
	{
		mlx_pixel_put(point->mlx_ptr, point->win_ptr, bres.x, bres.y,\
		point->coords[bres.col][bres.row].color);
		bres.x += xs;
		bres.y += ys;
	}
}

void			color_changing(t_bresnhelp bres, t_point *point)
{
	if (point->coords[(int)bres.y][(int)bres.x].col_snif)
		point->coords[(int)bres.y][(int)bres.x].color = (((bres.z1 > 0)\
		|| (bres.z > 0 && bres.z1 == 0)) ||\
		((bres.z1 < 0) || (bres.z < 0 && bres.z1 == 0))) ?\
		(point->coords[(int)bres.y][(int)bres.x].color +\
		(point->colorize)) : DEFAULT_COLOR;
	if (!point->coords[(int)bres.y][(int)bres.x].col_snif)
		point->coords[(int)bres.y][(int)bres.x].color = (((bres.z1 > 0)\
		|| (bres.z > 0 && bres.z1 == 0)) ||\
		((bres.z1 < 0) || (bres.z < 0 && bres.z1 == 0))) ?\
		(16710000 + (point->colorize)) : DEFAULT_COLOR;
}

void			bresenham(t_bresnhelp bres, t_point *point)
{
	bres.z = point->coords[(int)bres.y][(int)bres.x].z_val;
	bres.z1 = point->coords[(int)bres.y1][(int)bres.x1].z_val;
	bres.z *= point->shift_z;
	bres.z1 *= point->shift_z;
	color_changing(bres, point);
	if (point->zoom >= 1)
	{
		bres.x *= point->zoom;
		bres.y *= point->zoom;
		bres.x1 *= point->zoom;
		bres.y1 *= point->zoom;
	}
	if (point->shift_project)
	{
		iso(&bres.x, &bres.y, bres.z);
		iso(&bres.x1, &bres.y1, bres.z1);
	}
	bres.x += point->shift_x;
	bres.y += point->shift_y;
	bres.x1 += point->shift_x;
	bres.y1 += point->shift_y;
	if ((bres.x < 0 || bres.x > 1000) && (bres.y < 0 || bres.y > 1000) &&\
	(bres.x1 < 0 || bres.x1 > 1000) && (bres.y1 < 0 || bres.y1 > 1000))
		return ;
	bresnham_pp(bres, point);
}

void			draw_helper(t_bresnhelp coord, t_point *point)
{
	while (coord.col < point->height)
	{
		coord.row = 0;
		coord.x = 0;
		while (coord.row < point->width)
		{
			if (coord.row < point->width - 1)
			{
				coord.x1 = coord.x + 1;
				coord.y1 = coord.y;
				bresenham(coord, point);
			}
			coord.x++;
			coord.row++;
		}
		coord.y++;
		coord.col++;
	}
}

void			draw(t_point *point)
{
	t_bresnhelp coord;

	coord.col = 0;
	coord.y = 0;
	draw_helper(coord, point);
	coord.row = -1;
	coord.x = 0;
	while (++coord.row < point->width)
	{
		coord.col = 0;
		coord.y = 0;
		while (coord.col < point->height)
		{
			if (coord.col < point->height - 1)
			{
				coord.x1 = coord.x;
				coord.y1 = coord.y + 1;
				bresenham(coord, point);
			}
			coord.y++;
			coord.col++;
		}
		coord.x++;
	}
	drawmenu(point);
}
