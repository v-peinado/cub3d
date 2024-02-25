
#include "cub3d.h"

t_mlx init_mlx()
{
    t_mlx mlx;
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
    return (mlx);
}

void init_cub(t_cub3d *cub3d)
{
    cub3d->mlx = init_mlx();
	cub3d->background = background(cub3d);
	cub3d->map = map(cub3d);
	cub3d->player = player(cub3d);
    cub3d->raycast = raycast();
}

int	ft_close(t_cub3d *cub)
{
	if (!cub)
		return (1);
	if (cub->mlx.window)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	exit(EXIT_SUCCESS);
	return (0);
}
int main(int argv, char **argc)
{
    t_cub3d *cub3d;

    cub3d = malloc(sizeof(t_cub3d));
    if (!cub3d)
        return (1);
    parse_input(argv, argc, cub3d);
    start_game(cub3d);
    mlx_hook(cub3d->mlx.window, 2, 1L << 0, ft_key_press_handler, cub3d);
	mlx_hook(cub3d->mlx.window, 17, 1L << 17, ft_close, cub3d);
	mlx_loop(cub3d->mlx.mlx);
}