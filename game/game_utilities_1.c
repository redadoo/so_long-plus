/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:31:33 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 16:17:31 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vector2	obj_pos(char c, char **map)
{
	char		*str;
	t_vector2	pos;

	pos.x = 0;
	pos.y = 0;
	while (*map)
	{
		str = *map;
		while (*str)
		{
			if (*str == c)
				return (pos);
			pos.y++;
			str++;
		}
		pos.y = 0;
		pos.x++;
		map++;
	}
	return (pos);
}

void	change_sprite_player(void *param, t_vector2 old_pos, t_vector2 new_pos)
{
	int			img_width;
	int			img_height;
	t_program	*program;

	program = (t_program *)param;
	if (old_pos.x > new_pos.x)
	{
		program->man.sprite.img = give_sprite(param, SPRITE1);
		put_sprite(program, new_pos, program->man.sprite.img);
	}
	else if (old_pos.x < new_pos.x)
	{
		program->man.sprite.img = give_sprite(param, SPRITE2);
		put_sprite(program, new_pos, program->man.sprite.img);
	}
	else if (old_pos.y < new_pos.y)
	{
		program->man.sprite.img = give_sprite(param, SPRITE0);
		put_sprite(program, new_pos, program->man.sprite.img);
	}
	else if (old_pos.y > new_pos.y)
	{
		program->man.sprite.img = give_sprite(param, SPRITE3);
		put_sprite(program, new_pos, program->man.sprite.img);
	}
}

int	check_out_of_screen(void *param, t_gameobject *game)
{
	t_program	*program;
	char		**map;

	program = (t_program *)param;
	map = program->map.matrix_map;
	if (map && map[game->pos.y / 100][game->pos.x / 50] == '0')
		return (1);
	return (0);
}

void	*give_sprite(void *param, char *path)
{
	t_program	*program;
	int			img_width;
	int			img_height;

	program = (t_program *)param;
	return (mlx_xpm_file_to_image(program->mlx, path, &img_width, &img_height));
}
