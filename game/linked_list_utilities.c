/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:14 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/14 14:48:22 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

gameobject  *ft_lstlast(gameobject *lst)
{
	gameobject *current_element;

	current_element = lst;
	if (current_element == NULL)
	{
		return (NULL);
	}
	while (current_element->next != NULL)
	{
		current_element = current_element->next;
		printf("\n%i\n",current_element->exist);
	}
	return (current_element);
}
gameobject	*ft_lstnew(void *param,void *content)
{
    t_program *program;
	gameobject	*newnode;

    program = (t_program *)param;
	newnode = (gameobject *)malloc(sizeof(*newnode));
	if (!newnode)
		return (0);
	newnode->sprite.background_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH, &newnode->sprite.width, &newnode->sprite.height);
	newnode->sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &newnode->sprite.width, &newnode->sprite.height);
	newnode->next = NULL;
	return (newnode);
}

size_t	ft_lstsize(gameobject *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void push(gameobject** head_ref,void *param,int n)
{
	t_program	*program;

	program = (t_program *)param;

    gameobject* new_node = (gameobject*)malloc(sizeof(gameobject));
 
    new_tear(param,new_node,n);
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void new_tear(void *param, gameobject *tear,int n)
{
	t_program *program;

	program = (t_program *)param;
	tear->sprite.background_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->pos = pos_near_player(param);
	tear->exist = n;
}
