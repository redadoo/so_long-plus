/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/03 11:53:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program 	program;
	int			count;

	program.mlx = mlx_init();
	srand((unsigned)time(NULL));
	set_game(program,argc,argv);
}

void set_game(t_program program,int argc,char **argv)
{

	program.window = ft_new_window(program.mlx,  500, 500, "Rogue like Game");

	if(argc == 1)
		program.map.matrix_map = generatemap(program);
	else if(argc == 2)
		program.map.matrix_map = readmap(program,argv[1]);
	
	program.man = set_player(program,program.map.matrix_map);

	mlx_mouse_hook(program.window.reference, &mouse_event, &program);
	mlx_key_hook(program.window.reference, *key_hook, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
