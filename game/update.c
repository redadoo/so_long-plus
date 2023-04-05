/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/05 15:51:14 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;
	frame++;
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

	if(StartPos.y != program->man.pos.y || StartPos.x != program->man.pos.x)
	{
		mlx_put_image_to_window(program->mlx, program->window.reference,  imgBack.img ,  StartPos.x, StartPos.y);
		change_sprite_player(param,StartPos,program->man.pos);
	}	 
	return (keycode);
}

int mouse_event(int button, int x, int y, void *param)
{
    t_program *program = param;
    
    mlx_pixel_put(program->mlx, program->window.reference, x, y, 0xFFFFFF);
    
    return (1);
}

vector2 Lerp(vector2 a,vector2 b,float x)
{
	vector2 c;
	
 	c.x = a.x + (b.x - a.x) * x;
	c.y = a.y + (b.y - a.y) * x;
	return (c);
}
