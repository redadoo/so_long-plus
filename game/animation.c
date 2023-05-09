/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:11:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 15:31:19 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	coin_anim (void *param)
{
	t_program		*program = (t_program *)param;
	t_gameobject 	*coins;
	static int		frame;
	static int		count;


	frame++;
	if (program->env.coins.coin != NULL)
	{
		coins = program->env.coins.coin;
		while (coins != NULL)
		{
			if (frame == 60)
			{
				printf("\n count prima : %i ", count);
				change_sprite_coin(param,coins,count);
				count++;
				printf("\n count dopo : %i ", count);
			}
			if (frame ==  60 * 9)
			{
				frame = 0;
			}
			if (count >= 8)
				count = 0;
			coins = coins->next;
		}
	}

	return (0);
} 

void change_sprite_coin(void *param,t_gameobject *coin ,int count)
{
	t_program		*program = (t_program *)param;

	if (count == 0)
		coin->sprite = program->env.coins.sprite0;
	if (count == 1)
		coin->sprite = program->env.coins.sprite1;
	if (count == 2)
		coin->sprite = program->env.coins.sprite2;
	if (count == 3)
		coin->sprite = program->env.coins.sprite3;
	if (count == 4)
		coin->sprite = program->env.coins.sprite4;
	if (count == 5)
		coin->sprite = program->env.coins.sprite5;
	if (count == 6)
		coin->sprite = program->env.coins.sprite6;		
	if (count == 7)
		coin->sprite = program->env.coins.sprite7;
	if (count == 8)
		coin->sprite = program->env.coins.sprite8;

	mlx_put_image_to_window(program->mlx, program->window.reference,  program->env.coins.sprite0.b_img, coin->pos.y * 50, coin->pos.x * 100);
	mlx_put_image_to_window(program->mlx, program->window.reference, coin->sprite.img , coin->pos.y * 50, coin->pos.x * 100);

}