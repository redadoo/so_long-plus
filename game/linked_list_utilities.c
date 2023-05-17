/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:14 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/17 11:23:46 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	size_list(t_gameobject **head_ref)
{
	t_gameobject	*current;
	size_t			i;

	i = 0;
	current = (*head_ref);
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_gameobject	*find_node(t_gameobject **head_ref, size_t i)
{
	t_gameobject	*current;
	size_t			x;

	x = 0;
	current = (*head_ref);
	if (i == 0)
		return (current);
	while (x != i && current->next != NULL)
	{
		x++;
		current = current->next;
	}
	return (current);
}

void	free_list(t_gameobject **head_ref)
{
	t_gameobject	*current;

	while ((*head_ref) != NULL)
	{
		current = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		free(current->sprite.img);
	}
}

void	add_obj(t_gameobject **head, t_gameobject *node)
{
	t_gameobject	*current;

	current = (*head);
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}
