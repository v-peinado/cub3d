#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_length + x
			* (cub->mlx.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}