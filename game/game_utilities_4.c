/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:11:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/11 16:13:52 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_coin(void *param)
{
	t_program		*program;
	t_gameobject 	*coins;

	program = (t_program *)param;

	if (program->env.coins.coin != NULL)
	{
		coins = program->env.coins.coin;
		while (coins != NULL)
		{
			if (check_collect(param,coins->pos,program->man.pos))
			{
				printf("\ncollect");
			}
			coins = coins->next;
		}
	}
}

bool check_overlap_square(void *param,t_gameobject obj1,t_gameobject obj2)
{
		
}
bool check_overlap_circle(void *param,t_gameobject obj1,t_gameobject obj2)
{
		
}
bool check_overlap_circle_square(void *param,t_gameobject obj1,t_gameobject obj2)
{
		
}
