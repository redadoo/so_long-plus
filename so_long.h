/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:16:20 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/17 11:21:47 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <float.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <mlx.h>
# include <stdbool.h>
# include <math.h>

# define ANIMATION_FRAMES 12
# define UP_DIR 13
# define DOWN_DIR 1
# define LEFT_DIR 0
# define RIGHT_DIR 2
# define TEAR_PATH "Asset/player/tear.xpm"
# define TEAR_BACKGROUND_PATH "Asset/player/tear_background.xpm"
# define SPRITE0 "Asset/player/player0.xpm"
# define SPRITE1 "Asset/player/player1.xpm"
# define SPRITE2 "Asset/player/player2.xpm"
# define SPRITE3 "Asset/player/player3.xpm"
# define COIN0 "Asset/Enviroment/coinSprite/coin_sprite_0.xpm"
# define GRASSCOIN "Asset/Enviroment/coinSprite/grass_coin.xpm"
# define BLACKB "Asset/hud/black_background.xpm"
# define COLONNA "Asset/Enviroment/colonna.xpm"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_Rect
{
	t_vector2	tl;
	t_vector2	br;
}	t_Rect;

typedef struct s_Circle
{
	int			radius;
	t_vector2	center;
}	t_Circle;

typedef struct s_str
{
	int			value;
	t_vector2	pos;
}	t_str;

typedef struct s_data {
	void		*img;
	void		*b_img;
	char		*addr;
	int			width;
	int			height;
	void		*reference;
}	t_data;

typedef struct s_window {
	void		*reference;
	t_vector2	size;
}	t_screen;

typedef struct s_gameobject
{
	int					exist;
	int					dir;
	t_data				sprite;
	t_vector2			pos;
	t_vector2			b_pos;
	t_Rect				collider;
	t_Circle			c_collider;
	void				*reference;
	struct s_gameobject	*next;
}	t_gameobject;

typedef struct s_player
{
	void				*reference;
	t_str				coin;
	t_str				step;
	int					dir;
	int					walk;
	t_data				sprite;
	t_Rect				collider;
	t_vector2			pos;
	t_gameobject		*tear_gameobject;
}	t_player;

typedef struct s_coin {
	t_gameobject	*coin;
	t_data			sprite0;
}	t_coin;

typedef struct s_map
{
	char				**matrix_map;
	int					widht;
	int					height;
	t_gameobject		*wall;
}	t_map;

typedef struct s_env {
	t_coin			coins;
	t_gameobject	enemy;
}	t_env;

typedef struct s_program {
	void			*reference;
	void			*mlx;
	t_env			env;
	t_screen		window;
	t_player		man;
	t_map			map;
}	t_program;

t_screen		ft_new_window(t_program prog, int w, int h, char *str);
t_map			readmap(void *param, char *file);
t_player		set_player(t_program program, char **map);
int				key_hook(int keycode, void *param);
int				ft_update(void *param);
char			**CreateCubeMap(int ysize, int xsize, t_program program);
char			*assign_rows(bool wall, char *row, int size, t_program program);
void			PrintMatrix(char **Matrix);
int				Random01(void);
int				random_int(int min, int max);
void			set_game(t_program program, int argc, char **argv);
void			insert_wall(t_program program);
t_gameobject	*background_instance(t_program program, int i);
void			insert_lateral(t_program program);
void			insert_corner(t_program program);
void			insert_background(t_program program);
int				mouse_event(int button, int x, int y, void *param);
void			special_action(int keycode, void *param);
t_vector2		obj_pos(char c, char **map);
bool			check_move(void *param, t_vector2 pos, int dir);
void			change_sprite_player(void *param, t_vector2 op, t_vector2 np);
int				special_key_hook(int keycode, void *program);
void			attack(void *param);
t_vector2		move_toward(int dir, t_vector2 pos, int dist);
t_vector2		pos_near_player(void *param);
int				put_sprite(void *param, t_vector2 pos, void *img_ptr);
void			back_sprite(void *param, t_vector2 pos, t_data i);
size_t			size_list(t_gameobject **head_ref);
void			last_node(t_gameobject **head_ref, t_gameobject *node);
t_gameobject	*find_node(t_gameobject **head_ref, size_t i);
void			free_list(t_gameobject **head_ref);
void			add_obj(t_gameobject **head_ref, t_gameobject *node);
int				ft_close(int keycode, void *program);
void			*give_sprite(void *param, char *path);
int				check_out_of_screen_vector(void *param, t_vector2 pos);
void			spawn_tear(void *param);
void			manage_attack(void *param);
int				check_out_of_screen(void *param, t_gameobject *game);
void			move_tear(void *param, t_gameobject *tear);
void			print_warning(char *message);
void			null_error(char *message, void *program);
int				error(char *message);
int				file_linecount(char *file);
t_env			spawn_env(t_program program);
t_gameobject	*insert_wall_enviroment(t_program program);
void			check(t_program program);
void			check_wall(char c, int i, int j, t_program program);
void			check_env(char c, t_program program);
int 			close_w(int keycode, void *param);
t_gameobject	*put_wall_env(t_program program, int x, int y, int type);
int				check_type_wall(char **m, int x, int y, t_program program);
t_env			coin(t_program program);
int				coin_anim(void *param);
t_gameobject	*spawn_coin(t_program program, t_vector2 pos);
t_env			add_coin(t_program program, t_vector2 pos, t_env env);
t_coin			set_sprite_coin(t_program program, t_coin coins);
void			print_step_onscreen(void *mlx, void *win, int step);
char			*ft_itoa(int temp);
void			collect_coin(void *param);
bool			check_overlap_rectangle(void *param, t_Rect obj1, t_Rect obj2);
t_Rect			player_collider_updatate(void *param);
t_player		set_hud(t_program program);
void			hud_update(void *param);
bool			check_collide_wall(void *param,int x,int y);
t_Rect			fixed_player_collider_updatate(void *param,int x,int y);
bool 			overlap_circle_rectangle(t_Rect obj1,t_gameobject *obj2);
bool			collide_wall_tears(void *param,t_gameobject *tear);
bool			check_overlap_circle(void *p, t_gameobject o1, t_gameobject o2);
void			free_env(void *param);

#endif