/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 12:21:46 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move(char c,int x,void *param)
{
    t_program *program = (t_program *)param;
    int		img_width = 30;
	int		img_height = 30;

    if(c == 'y' && x < 0)
    {
        program->man.pos.y -= 4;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player3.xpm", &img_width, &img_height);
    }
    else if(c == 'y' && x > 0)
    {
        program->man.pos.y += 4;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player0.xpm", &img_width, &img_height);
    }
    else if(c == 'x' && x > 0)
    {
        program->man.pos.x += 4;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player2.xpm", &img_width, &img_height);
    }
    else if(c == 'x' && x < 0)
    {
        program->man.pos.x -= 4;
        program->man.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/player/player1.xpm", &img_width, &img_height);
    }
}

void special_action(char c,int keycode,void *param)
{
    if(keycode == 53)
        exit(0);
    if(keycode == 49)
        printf("azione");
}
