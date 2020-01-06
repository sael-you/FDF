/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 00:45:53 by hkchikec          #+#    #+#             */
/*   Updated: 2020/01/04 05:47:51 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_var(t_point *point)
{
	point->zoom = (0.8 * 1000) / point->width;
	point->shift_y = 400 - (point->height * point->zoom) / 2;
	point->shift_x = 830 - (point->width * point->zoom) / 2;
	point->shift_z = 1;
	point->colorize = 0;
}

int		check_file(char *arg)
{
	int		fd;
	int		*line;

	line = NULL;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(arg);
		ft_putendl(" does not exist");
		exit(-1);
	}
	if (read(fd, line, 0) < 0)
	{
		ft_putstr(arg);
		ft_putendl(" is invalide file");
		exit(-1);
	}
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	t_point *point;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	else
	{
		check_file(argv[1]);
		point = (t_point *)malloc(sizeof(t_point));
		read_map(point, argv[1]);
		init_var(point);
		point->mlx_ptr = mlx_init();
		point->win_ptr = mlx_new_window(point->mlx_ptr, 1322, 800, "FDF");
		draw(point);
		mlx_hook(point->win_ptr, 2, 0, bonus, point);
		mlx_loop(point->mlx_ptr);
	}
	return (0);
}
