/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:07 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/14 11:12:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int Random01()
{
    int i = rand() % 2;
    
    if (i == 0)
        return 0;    
    else
        return 1;
}

int RandomMax(int max)
{
    int i = rand() % max;
    
    if (i == 0)
        return 0;    
    else
        return i;
}

void PrintMatrix(char **Matrix)
{
    while (*Matrix)
    {
        printf("%s\n",*Matrix);
        Matrix++;
    }
    printf("ciao");
    return;
}