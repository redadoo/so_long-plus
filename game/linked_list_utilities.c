/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:14 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/17 13:55:52 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	last_node(gameobject **head_ref, gameobject *node)
{
	gameobject	*current;
	
	current = (*head_ref);

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = node;
	(*head_ref) = current;

}

size_t	size_list(gameobject **head_ref)
{
	gameobject	*current;
	size_t		i;

	i = 0;
	current = (*head_ref);
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

gameobject	*find_node(gameobject **head_ref, size_t i)
{
	gameobject	*current;
	size_t		x;

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

void	free_node_(gameobject **head_ref, gameobject *node)
{
	gameobject	*current;
	gameobject	*previus_node;

	current = (*head_ref);
	
	previus_node = find_prev_node(head_ref, node);

	node = NULL;
	
	free(node);
	
	previus_node->next = NULL;
	
}

gameobject	*find_prev_node(gameobject **head_ref, gameobject *node)
{
	gameobject	*current;

	current = (*head_ref);

	if (node == NULL)
		return (NULL);
	while (current->next != node && current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}