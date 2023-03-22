/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/21 11:10:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
/* 	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.img, program->sprite_position.x, program->sprite_position.y); */


	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_program *program = (t_program *)param;
/* 	if (keycode == 2)
		program->sprite_position.x += 10;
	else if(keycode == 0)
		program->sprite_position.x -= 10;
	else if(keycode == 13)
		program->sprite_position.y -= 10;
	else if(keycode == 1)
		program->sprite_position.y += 10;	
	if(!program->sprite.img)
		mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.img, program->sprite_position.x, program->sprite_position.y);
	else
		{
			player(*program);
			mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.img, program->sprite_position.x, program->sprite_position.y);
		} */
	printf("Key pressed -> %d\n", keycode);
	return (0);
}
