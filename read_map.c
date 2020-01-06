/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkchikec <hkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:10:34 by hkchikec          #+#    #+#             */
/*   Updated: 2020/01/04 06:05:36 by hkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		htoi_cond(char *hexval, int len, int *dec_val, int *base)
{
	int i;

	i = len;
	while (i > 0)
	{
		if (hexval[i] >= '0' && hexval[i] <= '9')
		{
			*dec_val += (hexval[i] - 48) * (*base);
			(*base) = (*base) * 16;
		}
		else if (hexval[i] >= 'A' && hexval[i] <= 'F')
		{
			*dec_val += (hexval[i] - 55) * (*base);
			(*base) = (*base) * 16;
		}
		else if (hexval[i] >= 'a' && hexval[i] <= 'f')
		{
			*dec_val += (hexval[i] - 87) * (*base);
			(*base) = (*base) * 16;
		}
		i--;
	}
}

int			ft_htoi(char *hexval)
{
	int		len;
	int		base;
	int		dec_val;

	dec_val = 0;
	len = ft_strlen(hexval);
	if (hexval[0] == '0' && hexval[1] == 'x')
	{
		base = 1;
		htoi_cond(hexval, len, &dec_val, &base);
	}
	if (dec_val >= 0 && dec_val <= 16777215)
		return (dec_val);
	return (16777215);
}

void		free_2d(char ***tmp)
{
	int		i;
	char	**tab;

	i = 0;
	tab = *tmp;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	*tmp = NULL;
}

int			split_col(t_point *point, char *str, int col, int row)
{
	int		i;
	int		hx;
	char	**tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			tmp = ft_strsplit(str, ',');
			point->coords[col][row].col_snif = 1;
			hx = ft_htoi(tmp[1]);
			free_2d(&tmp);
			return (hx);
		}
		i++;
	}
	point->coords[col][row].col_snif = 0;
	return (DEFAULT_COLOR);
}

void		read_map(t_point *points, char *path)
{
	char	*line;
	char	**splited_line;
	int		fd;

	line = NULL;
	splited_line = NULL;
	points->width = count_lenght(path);
	points->height = count_lines(path);
	points->coords =\
	(t_coords **)malloc(sizeof(t_coords *) * (points->height + 1));
	fd = open(path, O_RDONLY);
	read_file(fd, line, points, splited_line);
	close(fd);
}
