/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:11:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 12:39:51 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	coin_anim (void *param)
{
	t_program	*program = (t_program *)param;

	static int	frame;

	frame++;
	if (program->coin != NULL)
	{
		printf("ev");
	}
/* 	if (program->coin.exist == 1)
	{
		if (frame == ANIMATION_FRAMES)
		{
			program->coin.sprite.img = 
		}
		else if (frame >= ANIMATION_FRAMES * 8)
		{
			//program->sprite_position.y -= 1;
			frame = 0;
		}
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);  */
	if (frame >= ANIMATION_FRAMES * 8)
	{
		//program->sprite_position.y -= 1;
		frame = 0;
	}
	return (0);
} 