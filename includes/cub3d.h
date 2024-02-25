#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800


# define SOUTH		0
# define NORTH		1

# define WEST		2
# define EAST		3

# define WALK_SPEED		0.125
# define RUN_SPEED	    0.3
# define ROT_SPEED		0.075

/*
** Keyboard LETTERS LINUX
*/

# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define K_LEFT 65361
# define K_RIGHT 65363

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			old_dir_x;
	double			old_plane_x;
}				t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}			t_mlx;

typedef struct s_map 
{
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	char			player_dir;
	char			**matrix;
}				t_map;

typedef struct s_background
{
	unsigned int		floor;
	unsigned int		ceiling;
	t_mlx				*walls;
}			t_background;

typedef struct s_raycast
{
	bool	wall_hit;
	bool	side_hit;
	int		line_height;
	int		draw_from;
	int		draw_to;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	double	tex_wall_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}			t_raycast;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_background	background;
	t_raycast		raycast;
	char			*filepath;
}				t_cub3d;

void	my_mlx_pixel_put(t_cub3d *cub, int x, int y, int color);
void parse_input(int argv, char **argc, t_cub3d *cub3d);
void init_cub(t_cub3d *cub3d);
t_background background(t_cub3d *cub3d);
t_map map(t_cub3d *cub3d);
t_player player(t_cub3d *cub3d);
t_raycast raycast(void);\
int	ft_key_press_handler(int keycode, t_cub3d *cub);
int start_game(t_cub3d *cub);
#endif