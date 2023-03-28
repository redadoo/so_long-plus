/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 14:29:51 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->man.pos.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->man.pos.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->man.sprite.reference, program->man.pos.x, program->man.pos.y);

	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_program *program = (t_program *)param;
 	if (keycode == 2)
		program->man.pos.x += 10;
	else if(keycode == 0)
		program->man.pos.x  -= 10;
	else if(keycode == 13)
		program->man.pos.y -= 10;
	else if(keycode == 1)
		program->man.pos.y += 10; 

	printf("Key pressed -> %d\n", keycode);
	return (0);
}
