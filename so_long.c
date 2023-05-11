/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/11 15:28:20 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game(t_program program, int argc, char **argv)
{
	if (argc == 2)
		program.map = readmap(program.reference, argv[1]);
	else if (argc == 1)
		program.map.matrix_map = generatemap(program);

	program.window = ft_new_window(program, (program.map.widht * 50),(program.map.height * 100), "Rogue like Game");
	PrintMatrix(program.map.matrix_map);
	check(program);
	program.env = make_file_map(program);
	program.man = set_player(program, program.map.matrix_map);
	//mlx_string_put(program.mlx,program.window.reference,95,100,0xccccff,"step : ");
	//mlx_string_put(program.mlx,program.window.reference,95,100,0xccccff,"coin : ");
	mlx_hook(program.window.reference, 2, 1L << 1, *key_hook, &program);
	mlx_loop_hook(program.mlx, ft_update, &program);
	mlx_loop(program.mlx);
}

int	main(int argc, char **argv)
{
	t_program	program;

	program.mlx = mlx_init();
	set_game(program, argc, argv);
}
