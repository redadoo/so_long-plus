/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/17 10:15:55 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_screen	ft_new_window(t_program program, int widht, int height, char *name)
{
	int			x;
	t_screen	window;


	x = (program.map.height * 150) - (program.map.height * 100) - 180;
	window.reference = mlx_new_window(program.mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height - x;
	return (window);
}

