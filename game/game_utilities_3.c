/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:10:17 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 16:12:38 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_out_of_screen_vector(void *param, t_vector2 pos)
{
	t_program	*program;
	char		**map;

	program = (t_program *)param;
	map = program->map.matrix_map;
	if (map && map[pos.y / 10][pos.x / 10] == '0')
		return (1);
	return (0);
}

int	put_sprite(void *param, t_vector2 p, void *i)
{
	t_program		*program;

	program = (t_program *)param;

	mlx_put_image_to_window(program->mlx, program->window.reference, i, p.x, p.y);
	return (0);
}
int	put_comp_sprite(void *param, t_vector2 p, void *i,  t_vector2 o)
{
	t_program		*program;
	t_screen		window;

	program = (t_program *)param;
	window = program->window;
	mlx_put_image_to_window(program->mlx, window.reference, i, p.x, p.y);
	return (0);
}
int	ft_close(void *param)
{
	t_program		*program;

	program = (t_program *)param;
	free_list(&program->man.tear_gameobject);
	free(program->map.matrix_map);
	exit(0);
}