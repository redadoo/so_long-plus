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

t_map readmap(void *param, char *file)
{
	int				i;
	int				fd;
	int				len;
	char			**map;
	t_map			game_map;

	map = (char **)calloc((sizeof(char *)),file_linecount(file)+1);
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
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

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

t_env spawn_env(t_program program)
{
	return (coin(program));
}
int check_type_wall(char **m,int x,int y,t_program program)
{

		printf("\n x : %i | y : %i\n",x,y);
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
