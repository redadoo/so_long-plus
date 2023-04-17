/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:40:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/17 17:47:32 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

vector2	move_toward(int dir, vector2 pos, int dist)
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

vector2	pos_near_player(void *param)
{
	t_program	*program;
	vector2		pos;

	program = (t_program *)param;
	if (program->man.dir == UP_DIR)
	{
		pos.x = program->man.pos.x + 5;
		pos.y = program->man.pos.y - 13;
	}
	if (program->man.dir == DOWN_DIR)
	{
		pos.x = program->man.pos.x + 5;
		pos.y = program->man.pos.y + 52;
	}
	if (program->man.dir == LEFT_DIR)
	{
		pos.x = program->man.pos.x - 15;
		pos.y = program->man.pos.y + 10;
	}
	if (program->man.dir == RIGHT_DIR)
	{
		pos.x = program->man.pos.x + 25;
		pos.y = program->man.pos.y + 10;
	}
	return (pos);
}

int	put_sprite(void *param, vector2 p, void *i)
{
	t_program	*program;
	screen		window;

	program = (t_program *)param;
	window = program->window;
	mlx_put_image_to_window(program->mlx, window.reference, i, p.x, p.y);
	return (0);
}

int	put_background_sprite(void *param, vector2 posb, vector2 pos, t_data s)
{
	t_program	*program;

	program = (t_program *)param;
	put_sprite(param, posb, s.b_img);
	put_sprite(param, pos, s.img);
	return (0);
}
