/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:00:08 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 14:57:39 by evocatur         ###   ########.fr       */
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
			pos.y++;
			str++;
		}
		pos.y = 0;
		pos.x++;
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
	
	coins = malloc(sizeof(t_gameobject));
	coins->sprite.img =  mlx_xpm_file_to_image(program.mlx, COIN0, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference, coins->sprite.img , pos.y * 50, pos.x * 100);
	coins->pos = pos;
	coins->next = NULL;
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
	coins.sprite0.img = mlx_xpm_file_to_image(program.mlx, COIN0, &img_width, &img_height);
	coins.sprite1.img = mlx_xpm_file_to_image(program.mlx, COIN1, &img_width, &img_height);
	coins.sprite2.img = mlx_xpm_file_to_image(program.mlx, COIN2, &img_width, &img_height);
	coins.sprite3.img = mlx_xpm_file_to_image(program.mlx, COIN3, &img_width, &img_height);
	coins.sprite4.img = mlx_xpm_file_to_image(program.mlx, COIN4, &img_width, &img_height);
	coins.sprite5.img = mlx_xpm_file_to_image(program.mlx, COIN5, &img_width, &img_height);
	coins.sprite6.img = mlx_xpm_file_to_image(program.mlx, COIN6, &img_width, &img_height);
	coins.sprite7.img = mlx_xpm_file_to_image(program.mlx, COIN7, &img_width, &img_height);
	coins.sprite8.img = mlx_xpm_file_to_image(program.mlx, COIN8, &img_width, &img_height);
	return (coins);
}
