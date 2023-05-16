/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/16 13:56:04 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

<<<<<<< HEAD
t_map readmap(void *param, char *file)
=======
t_map	readmap(void *param, char *file)
>>>>>>> 2be5e29a4f0290257215231d9ce1f7d550afffaa
{
	int				i;
	int				fd;
	int				len;
	char			**map;
	t_map			game_map;

	map = (char **)calloc((sizeof(char *)), file_linecount(file)+1);
	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_linecount(file))
	{
		map[i] = get_next_line(fd);
		len = ft_strlen(map[i]);
		i++;
	}
	game_map.height = file_linecount(file);
	game_map.widht =  ft_strlen(map[0]);
	game_map.matrix_map = map;
	game_map.wall = NULL;
	close(fd);
	return (game_map);
}

int	file_linecount(char *file)
{
	char	c;	
	int		fd;	
	int		linecount;
	int		readcount;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (true)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

int	check_type_wall(char **m, int x, int y, t_program program)
{

		if (m[x][y - 1] == '0' && m[x][y + 1] == '0')
			return (1);
		else if (m[x][y - 1] == '1' && m[x][y + 1] == '0')
			return (4);
		else if (m[x][y - 1] == '1' && m[x][y + 1]== '1')
			return (3);	
		else if (m[x][y - 1] == '0' && m[x][y + 1]== '1')
			return (2);
	return (0);
}
