/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:54 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 16:07:04 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	return (0);
}

int	key_hook(int keycode, void *param)
{
	int		img_width = 30;
	int		img_height = 30;
	t_program *program = (t_program *)param;
	t_player player;
	t_data playerimag;
	player = program->man;
	printf("Key pressed -> %d\n", keycode);

	if(keycode == 0)
		program->man.pos.x -= 10;
	if(keycode == 1)
	{
		program->man.pos.y += 10;
	}
	if(keycode == 2)
	{
		player.sprite.img = mlx_xpm_file_to_image(program->mlx, "Asset/Player1.xpm", &img_width, &img_height);
		program->man.pos.x += 10;
	}
	if(keycode == 13)
		program->man.pos.y -= 10;

	playerimag.img = player.sprite.img;
	mlx_put_image_to_window(program->mlx, program->window.reference,  playerimag.img , program->man.pos.x, program->man.pos.y);
	mlx_destroy_image(program->mlx,playerimag.img);
	//program->man.sprite.img =mlx_xpm_file_to_image(program->mlx, "Asset/Player.xpm", &img_width, &img_height);
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
    t_program *program = param;
    
    mlx_pixel_put(program->mlx, program->window.reference, x, y, 0xFFFFFF);
    
    return (1);
}
