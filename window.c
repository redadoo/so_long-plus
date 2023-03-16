/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_windows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/13 11:34:17 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close ()
{
	exit(0);
}

screen	ft_new_window(void *mlx, int widht, int height, char *name)
{
	screen	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;

	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}