/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/16 12:44:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_program *vars)
{
	printf("Hello from key_hook!\n");
	printf("%i\n",keycode);
	return (0);
}


int	main(int argc, char **argv)
{
	t_program program;
	t_data	img;
	void *img2;
	int		img_width = 30;
	int		img_height = 30;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 800, 600, "test");
 	mlx_key_hook(program.window.reference, key_hook, &program);
/*	img2 = mlx_xpm_file_to_image(program.mlx, "plane.xpm", &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference, img2, 0, 0);
	program.sprite.img = mlx_xpm_file_to_image(program.mlx, "cube.xpm", &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference, program.sprite.img ,0, 30); */

	mlx_loop(program.mlx);
}