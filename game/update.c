/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 13:04:56 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;
    int		img_width = 30;
	int		img_height = 30;
	
	frame++;
/* 	if (frame == ANIMATION_FRAMES / 2)
	{
		program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player_idle_0.xpm", &img_width, &img_height);
		program->man.pos.y +=1;
	}
	else if (frame >= ANIMATION_FRAMES)
	{
		program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player_idle_1.xpm", &img_width, &img_height);
	}
	else if(frame >= ANIMATION_FRAMES * 2)
	{
		program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player_idle_2.xpm", &img_width, &img_height);
		program->man.pos.y -=1;
		frame = 0;
	} */
	//mlx_put_image_to_window(program->mlx, program->window.reference,program->man.sprite.img, program->man.pos.x, program->man.pos.y);
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
	if(keycode == 53 || keycode == 49)
		special_action('c',keycode,param);
	if(keycode == 0)
		move('x',-4,param);
	if(keycode == 1)
		move('y',+4,param);
	if(keycode == 2)
		move('x',+4,param);
	if(keycode == 13)
		move('y',-4,param);
	if(StartPos.y != program->man.pos.y || StartPos.x != program->man.pos.x)
	{
			mlx_put_image_to_window(program->mlx, program->window.reference,  imgBack.img ,  StartPos.x, StartPos.y );
			mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.sprite.img , program->man.pos.x, program->man.pos.y);
	}
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
    t_program *program = param;
    
    mlx_pixel_put(program->mlx, program->window.reference, x, y, 0xFFFFFF);
    
    return (1);
}
