/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/05 14:11:25 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move(char c,int x,void *param)
{
    vector2 pos;
    int		img_width;
	int		img_height;
    
    t_program *program = (t_program *)param;
    if(c == 'y' && x < 0 && check_move(program->map.matrix_map, program->man.pos.x ,program->man.pos.y - 4))
    {
        program->man.pos.y -= 6;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player3.xpm", &img_width, &img_height);
    }
    else if(c == 'y' && x > 0 && check_move(program->map.matrix_map, program->man.pos.x ,program->man.pos.y + 4))
    {
        program->man.pos.y += 6;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player0.xpm", &img_width, &img_height);
    }
    else if(c == 'x' && x > 0 && check_move(program->map.matrix_map, program->man.pos.x + 4,program->man.pos.y))
    {
        program->man.pos.x += 6;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player2.xpm", &img_width, &img_height);
    }
    else if(c == 'x' && x < 0 && check_move(program->map.matrix_map, program->man.pos.x - 4 ,program->man.pos.y))
    {
        program->man.pos.x -= 6;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player1.xpm", &img_width, &img_height);
    }
}

void special_action(int keycode,void *param)
{
    if(keycode == 53)
        exit(0);
    if(keycode ==  49)
        attack(param);
}

bool check_move(char **map,int x,int y)
{
    x /=10;
    y /=10;
    if(map[y][x] == '0')
    {
        return (true);
    }
    return (false);
}

void attack(void *param)
{
    t_program *program = (t_program *)param;
    t_data dart;
    int		img_width;
	int		img_height;
    gameobject attack;


    dart.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/dart.xpm", &img_width, &img_height);
    mlx_put_image_to_window(program->mlx, program->window.reference,  dart.img , program->man.pos.x , program->man.pos.y);
    attack.pos = program->man.pos;
    attack.sprite = dart;
    program->man.attack_gameobject = attack;
}