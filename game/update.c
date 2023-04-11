/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/11 16:26:51 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update_tears (void *param)
{
	t_program	*program = (t_program *)param;
	gameobject tear;
	tear = program->man.attack_gameobject;
	if(tear.exist == 2)
	{
		tear.pos = move_toward(tear.dir,tear.pos,2);
		if(check_out_of_screen(param,tear) != 0)
		{
			mlx_put_image_to_window(program->mlx, program->window.reference, tear.sprite.background_img, program->man.attack_gameobject.pos.x, program->man.attack_gameobject.pos.y);
			mlx_put_image_to_window(program->mlx, program->window.reference, tear.sprite.img, tear.pos.x , tear.pos.y);	
		}
		else
		{
			mlx_put_image_to_window(program->mlx, program->window.reference, tear.sprite.background_img, program->man.attack_gameobject.pos.x, program->man.attack_gameobject.pos.y);
			tear.exist = 0;
		}
		program->man.attack_gameobject = tear;
	}
	else if(tear.exist == 1)
	{
		tear.pos = move_toward(tear.dir,tear.pos,2);
		if(check_out_of_screen(param,tear) != 0)
		{
			put_sprite(param, program->man.attack_gameobject.pos, tear.sprite.background_img);
			put_sprite(param, tear.pos, tear.sprite.img);
		}
		tear.exist = 2; 
		tear.dir = program->man.dir;
		program->man.attack_gameobject = tear;
		return (0);
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

int	check_out_of_screen(void *param, gameobject game)
{
	t_program	*program;
	char		**map;

	program = (t_program *)param;
	map = program->map.matrix_map;
	if (map && map[game.pos.y / 10][game.pos.x / 10] == '0')
		return (1);
	return (0);
}
