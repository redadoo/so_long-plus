/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:16:20 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/26 16:17:52 by evocatur         ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector2;

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
	void				*reference;
	struct s_gameobject	*next;
}	t_gameobject;

typedef struct s_player
{
	void				*reference;
	int					life;
	int					dir;
	t_vector2			pos;
	t_data				sprite;
	t_gameobject		*tear_gameobject;
}	t_player;

typedef struct s_map
{
	char	**matrix_map;
	int		widht;
	int		height;
}	t_map;

typedef struct s_program {
	void			*reference;
	void			*mlx;
	t_screen		window;
	t_player		man;
	t_map			map;
}	t_program;

t_screen		ft_new_window(void *mlx, int widht, int height, char *name);
char			**readmap(void *param, char *file);
char			**generatemap(t_program program);
t_player		set_player(t_program program, char **map);
int				key_hook(int keycode, void *param);
int				ft_update(void *param);
char			**CreateCubeMap(int ysize, int xsize, t_program program);
char			*assign_rows(bool wall, char *row, int size, t_program program);
void			PrintMatrix(char **Matrix);
int				Random01(void);
char			**spawn_obj(char **map, int colum, int row, t_program program);
int				random_int(int min, int max);
void			set_game(t_program program, int argc, char **argv);
void			insert_wall(t_program program);
void			background_instance(t_program program);
void			insert_lateral(t_program program);
void			insert_corner(t_program program);
void			insert_background(t_program program);
int				mouse_event(int button, int x, int y, void *param);
void			special_action(int keycode, void *param);
t_vector2		obj_pos(char c, char **map);
void			spawn_enviroment(t_program program, char **map);
void			spawn_manage(t_program program, char **map);
void			spawn_collectable(t_program program, char **map);
bool			check_move(void *param, int x, int y);
t_vector2		random_pos(t_program program);
char			**procedural_map(char **map);
void			change_sprite_player(void *param, t_vector2 op, t_vector2 np);
int				special_key_hook(int keycode, void *param);
void			attack(void *param);
int				check_out_of_t_screen(void *param, t_gameobject *game);
t_vector2		move_toward(int dir, t_vector2 pos, int dist);
t_vector2		pos_near_player(void *param);
int				put_sprite(void *param, t_vector2 pos, void *img_ptr);
void			back_sprite(void *param, t_vector2 pos, t_data i);
size_t			size_list(t_gameobject **head_ref);
void			last_node(t_gameobject **head_ref, t_gameobject *node);
t_gameobject	*find_node(t_gameobject **head_ref, size_t i);
void			free_node_(t_gameobject **head_ref, t_gameobject *node);
t_gameobject	*find_prev_node(t_gameobject **head_ref, t_gameobject *node);
int				ft_close(void);
void			*give_sprite(void *param, char *path);
int				check_out_of_screen_vector(void *param, t_vector2 pos);
void			spawn_tear(void *param);
void			manage_attack(void *param);
int				check_out_of_screen(void *param, t_gameobject *game);
void			move_tear(void *param,t_gameobject *tear);
void			print_warning(char *message);
void			*null_error(char *message);
int				error(char *message);
int				file_linecount(char *file);
void			make_file_map(void *param, char **map);
void			place_background(void *param);
#endif