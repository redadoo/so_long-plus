/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 11:20:27 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game(t_program program, int argc, char **argv)
{
	if (argc == 1)
	{
		program.window = ft_new_window(program.mlx, 1040, 740, "Rogue like Game");
		program.map.matrix_map = generatemap(program);
	}
	else if (argc == 2)
	{
		program.map.matrix_map = readmap(program.reference, argv[1]);
		program.map.height = file_linecount(argv[1]);
		program.map.widht =  ft_strlen(program.map.matrix_map[1]);
		check(program);
		program.window = ft_new_window(program.mlx, (program.map.widht * 50),(program.map.height * 100), "Rogue like Game");
		make_file_map(program, program.map.matrix_map);
		PrintMatrix(program.map.matrix_map);
	}
	program.man = set_player(program, program.map.matrix_map);
	program.man.dir = 0;
	mlx_hook(program.window.reference, 2, 1L << 1, *key_hook, &program);
	mlx_loop_hook(program.mlx, ft_update, &program);
	mlx_loop(program.mlx);
}

int	main(int argc, char **argv)
{
	t_program	program;

	program.mlx = mlx_init();
	srand((unsigned)time(NULL));
	set_game(program, argc, argv);
}
