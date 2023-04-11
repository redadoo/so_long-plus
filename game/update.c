/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/11 16:45:42 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update_tears (void *param)
{
	t_program	*program;
	gameobject	tear;

	program = (t_program *)param;
	tear = program->man.attack_gameobject;
	if(tear.exist == 2)
	{
		tear.pos = move_toward(tear.dir,tear.pos,2);
		if(check_out_of_screen(param,tear) != 0)
			put_background_sprite(param, program->man.attack_gameobject.pos,tear.pos, tear.sprite);
		else
		{
			put_sprite(param, program->man.attack_gameobject.pos, tear.sprite.background_img);
			tear.exist = 0;
		}
		program->man.attack_gameobject = tear;
	}
	else if(tear.exist == 1)
	{
		tear.pos = move_toward(tear.dir,tear.pos,2);
		if(check_out_of_screen(param,tear) != 0)		
			put_background_sprite(param, program->man.attack_gameobject.pos, tear.pos, tear.sprite);
		tear.exist = 2; 
		tear.dir = program->man.dir;
		program->man.attack_gameobject = tear;
	}
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_program	*program;
	vector2		startpos;
	t_player	player;

	program = (t_program *)param;
	player = program->man;
	startpos = program->man.pos;
	if (keycode == 0 && check_move(program->map.matrix_map, program->man.pos.x - 3, program->man.pos.y))
		program->man.pos.x -= 3;
	if (keycode == 1 && check_move(program->map.matrix_map, program->man.pos.x, program->man.pos.y + 3))
		program->man.pos.y += 3;
	if (keycode == 2 && check_move(program->map.matrix_map, program->man.pos.x + 3, program->man.pos.y))
		program->man.pos.x += 3;
	if (keycode == 13 && check_move(program->map.matrix_map, program->man.pos.x, program->man.pos.y - 3))
		program->man.pos.y -= 3;
	special_key_hook(keycode, param);
	if (startpos.y != program->man.pos.y || startpos.x != program->man.pos.x)
	{
		program->man.dir = keycode;
		put_sprite(param, startpos, player.sprite.background_img);
		change_sprite_player(param, startpos, program->man.pos);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_pixel_put(program->mlx, program->window.reference, x, y, 0xFFFFFF);
	return (1);
}

int	special_key_hook(int keycode, void *param)
{
	t_program	*program;
	t_data		spirte;
	int			img_width;
	int			img_height;

	program = (t_program *)param;
	if (keycode == 49)
		attack(param);
	return (0);
}

