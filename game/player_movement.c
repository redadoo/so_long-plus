/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/11 14:10:55 by evocatur         ###   ########.fr       */
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

bool	check_move(t_program *program, t_vector2 pos,int dir)
{
	int x;
	int y;

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
	
	return (true);
}
