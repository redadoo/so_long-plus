/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/03 13:09:12 by evocatur         ###   ########.fr       */
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
    return (NULL);
}

