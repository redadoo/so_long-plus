/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:00:08 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/12 15:08:38 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_env coin(t_program program)
{
	char 			**map;
	char			*str;
	t_vector2		pos;
	t_gameobject	*last;
	t_env			env;

	pos.x = 0;
	pos.y = 0;
	map = program.map.matrix_map;
	env.coins = set_sprite_coin(program,env.coins);
	env.coins.coin = NULL;
	while (*map)
	{
		str = *map;
		while (*str)
		{
			if (*str == 'C')
				env = add_coin(program, pos,env);
			pos.x++;
			str++;
		}
		pos.x = 0;
		pos.y++;
		map++;
	}
	return (env);
}

t_env add_coin(t_program program,t_vector2 pos,t_env env)
{
	int			img_width;
	int			img_height;
	t_gameobject	*last;
	t_gameobject	*coins;
	t_vector2		temp;

	coins = malloc(sizeof(t_gameobject));
	coins->sprite.img =  mlx_xpm_file_to_image(program.mlx, COIN0, &img_width, &img_height);
	pos.y *= 100;
	pos.x *= 50;
	mlx_put_image_to_window(program.mlx, program.window.reference, coins->sprite.img , pos.x, pos.y);
	coins->pos = pos;
	coins->next = NULL;
	temp.x = (coins->pos.x - img_width / 2);
	temp.y = (coins->pos.y - img_height / 2);
	coins->collider.X1 = temp;
	temp.x = (coins->pos.x + img_width / 2);
	temp.y = (coins->pos.y + img_height / 2);
	coins->collider.Y2 = temp;
	coins->exist = 1;
 	if (!env.coins.coin)
	{
		env.coins.coin = coins;
	}	
	else
	{
		last = env.coins.coin;
		while (last->next != NULL)
			last = last->next;
		last->next = coins;	
	}
	return (env);
}
t_coin set_sprite_coin(t_program program,t_coin coins)
{
	int			img_width;
	int			img_height;

	coins.sprite0.b_img = mlx_xpm_file_to_image(program.mlx, GRASSCOIN, &img_width, &img_height);
	coins.sprite0.img = mlx_xpm_file_to_image(program.mlx, COIN0, &img_width, &img_height);
	return (coins);
}
