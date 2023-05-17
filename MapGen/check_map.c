/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:28:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/17 11:32:08 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check(t_program program)
{
	char **map;
	int i;
	int j;

	map = program.map.matrix_map;
	i = program.map.height;
	j = program.map.widht;

	if (i > j || !map)
		ft_close(program.reference);
	i = 0;
	j = 0;
	check_env('P', program);
	check_env('E', program);
	check_env('C', program);
	while (i < program.map.height)
	{
		while (j < program.map.widht)
		{
			check_wall(map[i][j], i, j, program);
			j++;
		}
		j = 0;
		i++;
	} 
}

void check_wall(char c, int i, int j,t_program program)
{
	if (((i == 0) || (i == program.map.height - 1)) && (j < program.map.widht - 1))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls",program.reference);
	}
	if ((j == 0) || (j == program.map.widht - 2))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls",program.reference);
	}
}

void check_env(char c,t_program program)
{
	int 	i;
	int 	j;
	int		count;
	char 	**map;

	map = program.map.matrix_map;
	i = 0;
	j = 0;
	count = 0;
	while (i < program.map.height)
	{
		while (j < program.map.widht)
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	} 
	if (count < 1)
		null_error("The map does not contain at least 1 exit, 1 collectible and 1 starting location.", program.reference);
}
