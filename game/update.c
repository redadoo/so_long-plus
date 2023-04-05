/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/05 17:33:44 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;
	vector2 dart_pos;
	t_data background;
	frame++;
	if(program->man.attack_gameobject.exist == 1)
	{
		background.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/dart_background.xpm", &background.width, &background.height);
		mlx_put_image_to_window(program->mlx, program->window.reference, background.img, program->man.attack_gameobject.pos.x, program->man.attack_gameobject.pos.y);
		if( program->man.dir == RIGHT_DIR && check_attack(param) != 0)
			mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.attack_gameobject.sprite.img, program->man.attack_gameobject.pos.x += 2, program->man.attack_gameobject.pos.y);
		else if( program->man.dir == LEFT_DIR && check_attack(param) != 0)
			mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.attack_gameobject.sprite.img, program->man.attack_gameobject.pos.x -= 2, program->man.attack_gameobject.pos.y);
		else if( program->man.dir == UP_DIR && check_attack(param) != 0)
			mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.attack_gameobject.sprite.img, program->man.attack_gameobject.pos.x , program->man.attack_gameobject.pos.y -=2);
		else if( program->man.dir == DOWN_DIR && check_attack(param) != 0)	
			mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.attack_gameobject.sprite.img, program->man.attack_gameobject.pos.x , program->man.attack_gameobject.pos.y +=2);	
	}
	if(frame >= 30)
		frame = 0;
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_program *program = (t_program *)param;
    vector2 StartPos;
	int		img_width = 30;
	int		img_height = 30;
	t_data imgBack;
	StartPos.x = program->man.pos.x;
	StartPos.y = program->man.pos.y;
	imgBack.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/grass.xpm", &img_width, &img_height);
 	if(keycode == 0 && check_move(program->map.matrix_map, program->man.pos.x-3 ,program->man.pos.y))
        program->man.pos.x -= 3;
	else if(keycode == 1 && check_move(program->map.matrix_map, program->man.pos.x ,program->man.pos.y + 3))
        program->man.pos.y += 3;
	else if(keycode == 2 && check_move(program->map.matrix_map, program->man.pos.x+3 ,program->man.pos.y))
        program->man.pos.x += 3;
	else if(keycode == 13 && check_move(program->map.matrix_map, program->man.pos.x ,program->man.pos.y - 3))
        program->man.pos.y -= 3;
	else
		special_key_hook(keycode,param);
	if(StartPos.y != program->man.pos.y || StartPos.x != program->man.pos.x)
	{
		program->man.dir = keycode;
		mlx_put_image_to_window(program->mlx, program->window.reference,  imgBack.img ,  StartPos.x, StartPos.y);
		change_sprite_player(param,StartPos,program->man.pos);
	}
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
    t_program *program = param;
    
    mlx_pixel_put(program->mlx, program->window.reference, x, y, 0xFFFFFF);
    
    return (1);
}

int special_key_hook(int keycode,void *param)
{
	t_program *program = (t_program *)param;
	t_data spirte;
	int	img_width;
	int img_height;

	if(keycode == 49)
		attack(param);
	return (0);
}

int check_attack(void *param)
{
	t_program	*program = (t_program *)param;
	vector2 	dart_pos;
	char 		**map;

	dart_pos = program->man.attack_gameobject.pos;
	map = program->map.matrix_map;
	if(map && map[dart_pos.y / 10][dart_pos.x / 10] == '0')
	{
		return (1);
	}
	return (0);
}