/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 15:58:24 by evocatur         ###   ########.fr       */
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
	int fd;
	char *line;
	int keycode;
	program.window = ft_new_window(program.mlx,  800, 600, "Rogue like Game");
	if(argc == 1)
		generatemap(program);
	else if(argc == 2)
		readmap(program,argv[1]);
	program.man = set_player(program);
	mlx_mouse_hook(program.window.reference, &mouse_event, &program);
	mlx_key_hook(program.window.reference, *key_hook, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
