/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:00:08 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/09 13:32:37 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void coin(t_program program)
{
	char 			**map;
	char			*str;
	t_vector2		pos;
	t_gameobject	*last;

	pos.x = 0;
	pos.y = 0;
	map = program.map.matrix_map;
	while (*map)
	{
		str = *map;
		while (*str)
		{
			if (*str == 'C')
				add_coin(program, pos);
			pos.y++;
			str++;
		}
		pos.y = 0;
		pos.x++;
		map++;
	}
}

void add_coin(t_program program,t_vector2 pos)
{
	int				img_width;
	int				img_height;
	t_gameobject	*last;
	t_gameobject	*coins;

	coins = (t_gameobject *)malloc(sizeof(t_gameobject));
	if (!coins)
		return ;
	coins->sprite.img = mlx_xpm_file_to_image(program.mlx, COIN0, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference, coins->sprite.img , pos.y * 50, pos.x * 100);
	coins->pos = pos;
	coins->next = NULL;	
	if (program.coin == NULL)
		program.coin = coins;
	else 
	{
		while (program.coin->next != NULL)
		{
			printf("sadasd");
			program.coin = program.coin->next;
		} 
		program.coin = coins;	
	}
}
