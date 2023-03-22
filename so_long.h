#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 15
# endif

typedef struct    t_vector
{
    int    x;
    int    y;
    int    z;
}                vector3;

typedef struct    s_vector
{
    int    x;
    int    y;
}                vector2;

typedef struct    s_data {
    void       *img;
    char       *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}                t_data;

typedef struct    s_window {
    void        *reference;
    vector2      size;
}                screen;

typedef struct    s_program {
    void           *reference;
    void           *mlx;
    screen         window;
}                  t_program;

typedef struct  s_player 
{
    void            *reference;
    t_data          Sprite;
    int             life;
    vector2          pos;
}               t_player;

screen    ft_new_window(void *mlx, int widht, int height, char *name);
void readmap(t_program program ,char *file);
void generatemap(t_program program);
void test(t_program program);
void set_player(t_program program);
void map(int n,char **argv,t_program program);
int	key_hook(int keycode, void *param);
int	ft_update (void *param);
void place_background(t_program program);
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
void set_game(t_program program,int argc,char **argv);

#endif
