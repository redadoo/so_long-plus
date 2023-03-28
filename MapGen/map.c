/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 13:06:55 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void generatemap(t_program program)
{
    char    **Matrix;
    Matrix = CreateCubeMap(program.window.size.x / 10,program.window.size.y / 10,program);    
}

void readmap(t_program program ,char *file)
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
    return;
}

