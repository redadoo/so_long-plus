#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>


char **CreateCubeMap(int ysize,int xsize);
char *FillMatrix(bool wall, char *row,int size);
void PrintMatrix(char **Matrix);
int Random01();
int RandomMax(int max);
char    **ProceduralMap(char **map,int lenghtmatrix,int row,int colum);
char    **MapPlace(char **map,int lenghtmatrix,int colum,int row);
int RandomMaxMin(int max,int min);
int random_int(int min, int max);
void PlaceSmallWall(char **map,int x,int j);
void LongWall(char **map,int x,int j);

#endif