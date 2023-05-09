/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 12:01:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update(void *param)
{
	t_program	*program;
	t_vector2	pos_t;

	program = (t_program *)param;
	manage_attack(param);
	coin_anim(param);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_program	*program;
	t_vector2	startpos;
	t_player	player;

	program = (t_program *)param;
	player = program->man;
	startpos = program->man.pos;
	special_key_hook(keycode, param);
	if (keycode == 0 && check_move(program, player.pos,keycode))
		program->man.pos.x -= 6;
	else if (keycode == 1 && check_move(program, player.pos,keycode))
		program->man.pos.y += 6;
	else if (keycode == 2 && check_move(program, player.pos,keycode))
		program->man.pos.x += 6;
	else if (keycode == 13 &&check_move(program, player.pos,keycode))
		program->man.pos.y -= 6;
	if (startpos.y != program->man.pos.y || startpos.x != program->man.pos.x)
	{
		put_sprite(param, startpos, player.sprite.b_img);
		change_sprite_player(param, startpos, program->man.pos);
		program->man.dir = keycode;	
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
	t_data		spirte;
	int			img_width;
	int			img_height;

	if (keycode == 53)
		ft_close(param);
	if (keycode == 49)
		attack(param);
	return (0);
}
