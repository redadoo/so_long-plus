/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:31:33 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/14 17:52:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

vector2 obj_pos(char c,char **map)
{
	char	*str;
	vector2 pos;
	int		x;
	int		j;

	x = 0;
	j = 0;
	while (*map)
	{
		str = *map;
		while (*str)
		{
			if(*str == c)
			{
				pos.x = x;
				pos.y = j;
				return (pos);
			}
			j++;
			str++;
		}
		j = 0;
		x++;
		map++;
	}
	return (pos);
}

void change_sprite_player(void *param,vector2 old_pos,vector2 new_pos)
{
	t_program *program = (t_program *)param;
	t_data spirte;
	int	img_width;
	int img_height;

	if(old_pos.x > new_pos.x)
	{
		program->man.sprite.img =  mlx_xpm_file_to_image(program->mlx, "Asset/player/player1.xpm", &program->man.sprite.width, &program->man.sprite.height);
		mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.sprite.img , new_pos.x, new_pos.y);
	}
	else if(old_pos.x < new_pos.x)
	{
		program->man.sprite.img =  mlx_xpm_file_to_image(program->mlx, "Asset/player/player2.xpm", &program->man.sprite.width, &program->man.sprite.height);
		mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.sprite.img , new_pos.x, new_pos.y);
	}
	else if(old_pos.y < new_pos.y)
	{
		program->man.sprite.img =  mlx_xpm_file_to_image(program->mlx, "Asset/player/player0.xpm", &program->man.sprite.width, &program->man.sprite.height);
		mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.sprite.img , new_pos.x, new_pos.y);
	}
	else if(old_pos.y > new_pos.y)
	{
		program->man.sprite.img =  mlx_xpm_file_to_image(program->mlx, "Asset/player/player3.xpm", &program->man.sprite.width, &program->man.sprite.height);
		mlx_put_image_to_window(program->mlx, program->window.reference,  program->man.sprite.img , new_pos.x, new_pos.y);
	}
}

vector2 Lerp(vector2 a,vector2 b,float x)
{
	vector2 c;
	
 	c.x = a.x + (b.x - a.x) * x;
	c.y = a.y + (b.y - a.y) * x;
	return (c);
}

int	check_out_of_screen(void *param, gameobject *game)
{
	t_program	*program;
	char		**map;

	program = (t_program *)param;
	map = program->map.matrix_map;
	if (map && map[game->pos.y / 10][game->pos.x / 10] == '0')
		return (1);
	return (0);
}