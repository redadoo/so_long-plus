/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 10:50:52 by evocatur         ###   ########.fr       */
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
	//printf("\n %i %i \n",program->window.size.x,program->window.size.y);
	//printf("\nheight :%i  %i (%i) %i(%i) keycode ; %i\n",map.height,x,x/50,y,y/100,dir);
	//printf("%c",map.matrix_map[y / 100][x / 50]);
	if (y < 54 || y > program->window.size.y - 103 || x < 0 || x > program->window.size.x - 20)
		return (false);
	
	return (true);
}
