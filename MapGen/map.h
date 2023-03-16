/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:29:36 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/16 13:31:14 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>

char **CreateCubeMap(int ysize,int xsize);
char *FillMatrix(bool wall, char *row,int size);
void PrintMatrix(char **Matrix);
int Random01();
int RandomMax(int max);
char    **ProceduralMap(char **map,int lenghtmatrix,int row,int colum);
char    **MapPlace(char **map,int lenghtmatrix,int colum,int row);
int random_int(int min, int max);
void PlaceSmallWall(char **map,int x,int j,int xmax,int ymax);
void LongWall(char **map,int x,int j,int xmax,int ymax);
int Distance(int x1,int x2,int y1,int y2);


#endif