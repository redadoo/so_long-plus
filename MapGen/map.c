/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/31 16:41:59 by evocatur         ###   ########.fr       */
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

char **readmap(t_program program ,char *file)
{   
    int fd;
    char **matrix;
    char *line;
    int test;

    test = 0;
    fd = open(file, O_RDONLY);
    while (true)
    {
        line = get_next_line(fd);
        *matrix = (char *)malloc(4 * sizeof(char));
        //*matrix = line;
        if(!line)
            break ;
        //matrix++;
        //printf("%s",*matrix);
    }
    //program.window = ft_new_window(program.mlx, test * 100, test * 100, "Rogue like Game");
    return (NULL);
}

