/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:40:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/11 15:00:13 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vector2	move_toward(int dir, t_vector2 pos, int dist)
{
	if (dir == UP_DIR)
		pos.y -= dist;
	else if (dir == DOWN_DIR)
		pos.y += dist;
	else if (dir == RIGHT_DIR)
		pos.x += dist;
	else if (dir == LEFT_DIR)
		pos.x -= dist;
	return (pos);
}

t_vector2	pos_near_player(void *param)
{
	t_vector2		player_pos;
	t_vector2		pos;
	t_program		*program;

	program = (t_program *)param;
	player_pos = program->man.pos;
	if (program->man.dir == UP_DIR)
	{
		pos.x = player_pos.x + 5;
		pos.y = player_pos.y - 13;
	}
	else if (program->man.dir == DOWN_DIR)
	{
		pos.x = player_pos.x + 5;
		pos.y = player_pos.y + 52;
	}
	else if (program->man.dir == LEFT_DIR)
	{
		pos.x = player_pos.x - 15;
		pos.y = player_pos.y + 10;
	}
	else if (program->man.dir == RIGHT_DIR)
	{
		pos.x = player_pos.x + 25;
		pos.y = player_pos.y + 10;
	}
	return (pos);
}

void	back_sprite(void *param, t_vector2 pos, t_data i)
{
	t_program		*program;

	program = (t_program *)param;
	put_sprite(param, pos, i.b_img);
	put_sprite(param, pos, i.img);
}

void	print_step_onscreen(void *mlx, void *win, int step)
{
	char	*str;

	str = ft_itoa(step);
	mlx_string_put(mlx, win, 170, 100, 0xccccff, str);
}
