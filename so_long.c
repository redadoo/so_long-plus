/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:56:38 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/12 16:43:44 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player set_hud(t_program program)
{
	t_player hud;
	hud.step.pos.x = 95;
	hud.step.pos.y = program.window.size.y + 20;
	hud.step.value = 0;
	hud.coin.pos.x = 95;
	hud.coin.pos.y = program.window.size.y + 50;
	hud.step.coin = 0;
	mlx_string_put(program.mlx,program.window.reference, 95, program.window.size.y + 20,0xccccff,"step : ");
	mlx_string_put(program.mlx,program.window.reference, 155,program.window.size.y + 20,0xccccff,"0");
	mlx_string_put(program.mlx,program.window.reference, 95, program.window.size.y + 50,0xccccff,"coin : ");
	mlx_string_put(program.mlx,program.window.reference, 155,program.window.size.y + 50,0xccccff,"0");
	return (hud);
}
void	set_game(t_program program, int argc, char **argv)
{
	if (argc == 2)
		program.map = readmap(program.reference, argv[1]);
	else if (argc == 1)
		program.map.matrix_map = generatemap(program);

	program.window = ft_new_window(program, (program.map.widht * 50),(program.map.height * 150), "Rogue like Game");
	PrintMatrix(program.map.matrix_map);
	check(program);
	program.man = set_hud(program);
	program.env = make_file_map(program);
	program.man = set_player(program, program.map.matrix_map);
	set_hud(program);
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
