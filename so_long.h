#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>
# include <mlx.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct    t_vector
{
    int    x;
    int    y;
    int z;
}                vector3;

typedef struct    s_vector
{
    int    x;
    int    y;
}                vector2;

typedef struct    s_data {
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}                t_data;

typedef struct    s_window {
    void        *reference;
    vector2    size;
}                screen;

typedef struct    s_program {
    void        *reference;
    void        *mlx;
    screen        window;
    t_data        sprite;
    vector2        sprite_position;
}                t_program;

screen    ft_new_window(void *mlx, int widht, int height, char *name);

#endif
