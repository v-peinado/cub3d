#include "cub3d.h"

static bool	ft_is_wall(float x, float y, t_cub3d *cub)
{
	char	**worldmap;

	worldmap = cub->map.matrix;
	if (worldmap[(int)x][(int)y] == '1')
		return (true);
	return (false);
}
static void	ft_move_left_right(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_A)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_y * \
				(ROT_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_y * ROT_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_x * (ROT_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_x * ROT_SPEED;
	}
	if (keycode == KEY_D)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_y * \
				(ROT_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_y * ROT_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_x * (ROT_SPEED + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_x * ROT_SPEED;
	}
}
static void	ft_move_up_down(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_W)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_x * \
				(ROT_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_x * ROT_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_y * (ROT_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_y * ROT_SPEED;
	}
	if (keycode == KEY_S)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_x * \
				(ROT_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_x * ROT_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_y * (ROT_SPEED + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_y * ROT_SPEED;
	}
}

int	ft_key_press_handler(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		ft_close(cub);
	ft_move_up_down(keycode, cub);
	ft_move_left_right(keycode, cub);
	//ft_move_rotate(keycode, cub);
	start_game(cub);
	return (0);
}