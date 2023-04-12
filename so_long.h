#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <float.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <mlx.h>
# include <stdbool.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 12
# endif

# ifndef UP_DIR
#  define UP_DIR 13
# endif

# ifndef DOWN_DIR
#  define DOWN_DIR 1
# endif

# ifndef LEFT_DIR
#  define LEFT_DIR 0
# endif

# ifndef RIGHT_DIR
#  define RIGHT_DIR 2
# endif

# ifndef TEAR_PATH
#  define TEAR_PATH "Asset/player/tear.xpm"
# endif

# ifndef TEAR_BACKGROUND_PATH
#  define TEAR_BACKGROUND_PATH "Asset/player/tear_background.xpm"
# endif

typedef struct    s_vector
{
	int    x;
	int    y;
}                vector2;

typedef struct    s_data {
	void		*img;
	void		*background_img;
	char		*addr;
	int			width;
	int			height;
	void		*reference;
}                t_data;

typedef struct    s_window {
	void        *reference;
	vector2      size;
}                screen;
 
typedef struct  s_gameobject 
{
				int exist;
				void *reference;
				vector2 pos;
				int	dir;
				t_data sprite;
}				gameobject;

typedef struct  s_player 
{
	void            *reference;
	t_data          sprite;
	int             life;
	vector2         pos;
	gameobject		attack_gameobject;
	int				dir;
}               t_player;

typedef struct s_map{

	char        **matrix_map;
	int         widht;
	int         height;

}             t_map;

typedef struct    s_program {
	void           *reference;
	void           *mlx;
	screen         window;
	t_player       man;
	t_map          map;
}                  t_program;

int	ft_update (void *param);
screen    ft_new_window(void *mlx, int widht, int height, char *name);
char **readmap(t_program program ,char *file);
char **generatemap(t_program program);
t_player set_player(t_program program,char **map);
void map(int n,char **argv,t_program program);
int	key_hook(int keycode, void *param);
int	ft_update_tears (void *param);
void place_background(t_program program);
char **CreateCubeMap(int ysize,int xsize,t_program program);
char *assign_rows(bool wall, char *row,int size,t_program program);
void PrintMatrix(char **Matrix);
int Random01();
char    **spawn_obj(char **map,int lenghtmatrix,int colum,int row,t_program program);
int random_int(int min, int max);
void set_game(t_program program,int argc,char **argv);
void insert_wall(t_program program);
void background_instance(t_program program);
void insert_lateral(t_program program);
void insert_corner(t_program program);
void insert_background(t_program program);
int mouse_event(int button, int x, int y, void *param);
void special_action(int keycode,void *param);
vector2 obj_pos(char c,char **map);
void spawn_enviroment(t_program program,char **map);
void spawn_manage(t_program program,char **map);
void spawn_collectable(t_program program,char **map);
bool check_move(void *param,int x,int y)
vector2 random_pos(t_program program);
char **procedural_map(char **map);
vector2 Lerp(vector2 a,vector2 b,float x);
void change_sprite_player(void *param,vector2 old_pos,vector2 new_pos);
int special_key_hook(int keycode,void *param);
void attack(void *param);
int check_out_of_screen(void *param,gameobject game);
vector2 move_toward(int dir,vector2 pos,int dist);
void attack_exist(void *param);
vector2 pos_near_player(void *param);
int put_sprite(void *param,vector2 pos,void *img_ptr);
int put_background_sprite(void *param,vector2 pos_b,vector2 pos_s,t_data sprite);


#endif
