#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

char **CreateCubeMap(int ysize,int xsize);
char *FillMatrix(bool wall, char *row,int size);
void PrintMatrix(char **Matrix);

#endif