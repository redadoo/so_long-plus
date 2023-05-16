/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/16 16:52:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	special_action(int keycode, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	if (keycode == 53)
		exit(0);
}

bool	check_move(void *param, t_vector2 pos,int dir)
{
	t_program	*program;
	int x;
	int y;

	program = (t_program *)param;
	x = pos.x;
	y = pos.y;

	if (dir == 1)
		y = y + 16;
	if (dir == 13)
		y = y - 16;
	if (dir == 0)
		x = x - 16;
	if (dir == 2)
		x = x + 16;
	if (y < 54 || y > program->window.size.y - 103 || x < 0 || x > program->window.size.x - 20)
		return (false);
	if (!check_collide_wall(param,x,y))
	{
		return (false);
	}
	return (true);
}

t_Rect player_collider_updatate(void *param)
{
	t_program	*program;
	t_player	player;
	t_vector2	temp;
	int			img_width;
	int			img_height;

	program = (t_program *)param;
	player = program->man;
	img_width = player.sprite.width;
	img_height = player.sprite.height;
	temp.x = (player.pos.x - img_width / 2);
	temp.y = (player.pos.y - img_height / 2);
	player.collider.tl = temp;
	temp.x = (player.pos.x + img_width / 2);
	temp.y = (player.pos.y + img_height / 2) + 10;
	player.collider.br = temp;
	return (player.collider);
}

t_Rect fixed_player_collider_updatate(void *param,int x,int y)
{
	t_program	*program;
	t_player	player;
	t_vector2	temp;
	int			img_width;
	int			img_height;

	program = (t_program *)param;
	player = program->man;
	img_width = player.sprite.width;
	img_height = player.sprite.height;
	temp.x = (x - img_width / 2) + 12;
	temp.y = (y - img_height / 2)+ 12;
	player.collider.tl = temp;
	temp.x = (x + img_width / 2) - 12;
	temp.y = (y + img_height / 2);
	player.collider.br = temp;
	return (player.collider);
}