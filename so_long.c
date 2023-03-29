/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 12:51:53 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char **argv)
{
	int count;
	srand((unsigned)time(NULL));
	t_program program;
	program.mlx = mlx_init();
	set_game(program,argc,argv);
}

void set_game(t_program program,int argc,char **argv)
{
	char **map;

	program.window = ft_new_window(program.mlx,  600, 400, "Rogue like Game");

	if(argc == 1)
		map = generatemap(program);
	else if(argc == 2)
		map = readmap(program,argv[1]);
	
	program.man = set_player(program,map);

	mlx_mouse_hook(program.window.reference, &mouse_event, &program);
	mlx_key_hook(program.window.reference, *key_hook, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
