/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 12:29:03 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

char **generatemap(t_program program)
{
	char    **Matrix;
	program.map.height = program.window.size.y / 10;
	program.map.widht  = program.window.size.x / 10;
	Matrix = CreateCubeMap(program.window.size.x / 10,program.window.size.y / 10,program);   
	program.map.matrix_map = Matrix;
	return (Matrix);
}

char **readmap(void *param, char *file)
{
	int				i;
	int				fd;
	int				len;
	char			**map;
	t_program		*program;

	program = (t_program *)param;
	map = (char **)calloc((sizeof(char *)),file_linecount(file)+1);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_linecount(file))
	{
		map[i] = get_next_line(fd);
		len = ft_strlen(map[i]);
		i++;
	}
	close(fd);
	return (map);
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

