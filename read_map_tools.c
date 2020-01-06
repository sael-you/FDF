/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:43:24 by sael-you          #+#    #+#             */
/*   Updated: 2020/01/04 06:08:04 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_lines(char *path)
{
	int		counter;
	char	*line;
	int		fd;

	line = NULL;
	counter = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		counter++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (counter);
}

void		return_erro(void)
{
	ft_putendl("Found wrong line length. Exiting.");
	exit(-1);
}

int			count_lenght(char *path)
{
	char	*line;
	int		counter;
	char	**splited_line;
	int		fd;
	int		tmp;

	line = NULL;
	tmp = 0;
	counter = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		splited_line = ft_strsplit(line, ' ');
		free(line);
		counter = 0;
		while (splited_line[counter])
			counter++;
		free_2d(&splited_line);
		if (tmp != 0 && counter < tmp)
			return_erro();
		(tmp == 0) ? tmp = counter : 1;
		(tmp < counter) ? counter = tmp : 1;
	}
	close(fd);
	return (counter);
}

void		parser(char **splited_line, t_point *points, t_readhelp coord)
{
	while (coord.row < points->width)
	{
		coord.j = 0;
		while (splited_line[coord.j] && coord.row < points->width)
		{
			points->coords[coord.col][coord.row].color =\
			split_col(points, splited_line[coord.j], coord.col, coord.row);
			points->coords[coord.col][coord.row].z_val =\
			ft_atoi(splited_line[coord.j]);
			coord.row++;
			coord.j++;
		}
	}
}

void		read_file(int fd, char *line, t_point *points, char **splited_line)
{
	t_readhelp	coord;

	coord.i = -1;
	coord.col = 0;
	while (get_next_line(fd, &line) > 0)
	{
		coord.row = 0;
		points->coords[++coord.i] =\
		(t_coords *)malloc(sizeof(t_coords) * (points->width));
		splited_line = ft_strsplit(line, ' ');
		parser(&splited_line[coord.j], points, coord);
		coord.col++;
		free(line);
		line = NULL;
		free_2d(&splited_line);
	}
}
