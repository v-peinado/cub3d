#include "cub3d.h"

t_player player(t_cub3d *cub3d)
{
    t_player player;
    player.pos_x = cub3d->map.player_x;
    player.pos_y = cub3d->map.player_y;
    player.dir_x = 1;
	player.dir_y = 0;
    player.plane_x = 0;
	player.plane_y = -0.66;
    player.old_dir_x = 0;
	player.old_plane_x = 0;
    return (player);
}