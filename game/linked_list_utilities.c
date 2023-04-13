/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:14 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/13 18:09:41 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

gameobject  *ft_lstlast(gameobject *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
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