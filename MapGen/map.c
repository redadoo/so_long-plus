/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/27 12:30:00 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void place_wall(t_program program, char **Matrix,int widht,int height)
{
    int		i;
	int		j;
    int     d;
    int     m;
    i = 0;
    j = 0;
    d = 0;
    m = 0;
    while (i != widht)
    {
        while(j != height)
        {
            if(i == 0 && Matrix[i][j] == '1')
                d = insert_upper_wall(d,program);
            else if(i == (widht - 1) && Matrix[i][j] == '1')
                m = insert_down_wall(m,program);
            j++;
        }
        j = 0;
        i ++;
    }
}

void generatemap(t_program program)
{
    char    **Matrix;
    int     widht;
    int     height;
    Matrix = CreateCubeMap(program.window.size.x / 10,program.window.size.y / 10);
    t_data wall;
    height = program.window.size.y / 10;
    widht = program.window.size.x / 10;
    //place_wall(program,Matrix,height,widht);
    
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