#include "cub3d.h"

void fill_background_struct(t_cub3d *cub3d, t_background *background)
{
    void *img_south;
    void *img_north;
    void *img_west;
    void *img_east;
    int x = 64;
    int y = 64;

    img_south = mlx_xpm_file_to_image(cub3d->mlx.mlx, "src/textures/south.xpm", &x, &y);
    printf("img_south: %p\n", img_south);
    img_north = mlx_xpm_file_to_image(cub3d->mlx.mlx, "src/textures/north.xpm", &x, &y);
    printf("img_north: %p\n", img_north);
    img_west = mlx_xpm_file_to_image(cub3d->mlx.mlx, "src/textures/west.xpm", &x, &y);
    printf("img_west: %p\n", img_west);
    img_east = mlx_xpm_file_to_image(cub3d->mlx.mlx, "src/textures/east.xpm", &x, &y);
    printf("img_east: %p\n", img_east);
    background->walls[SOUTH].img = img_south;
    background->walls[NORTH].img = img_north;
    background->walls[WEST].img = img_west;
    background->walls[EAST].img = img_east;
    background->walls[SOUTH].addr = mlx_get_data_addr(img_south, &background->walls[SOUTH].bits_per_pixel, &background->walls[SOUTH].line_length, &background->walls[SOUTH].endian);
    printf("addr: %p\n", background->walls[SOUTH].addr);
    background->walls[NORTH].addr = mlx_get_data_addr(img_north, &background->walls[NORTH].bits_per_pixel, &background->walls[NORTH].line_length, &background->walls[NORTH].endian);
    printf("addr: %p\n", background->walls[NORTH].addr);
    background->walls[WEST].addr = mlx_get_data_addr(img_west, &background->walls[WEST].bits_per_pixel, &background->walls[WEST].line_length, &background->walls[WEST].endian);
    printf("addr: %p\n", background->walls[WEST].addr);
    background->walls[EAST].addr = mlx_get_data_addr(img_east, &background->walls[EAST].bits_per_pixel, &background->walls[EAST].line_length, &background->walls[EAST].endian);
    printf("addr: %p\n", background->walls[EAST].addr);
}

t_background background(t_cub3d *cub3d)
{
    t_background background;
    background.floor = 0x00ff00;
    background.ceiling = 0xccc000;
    background.walls = malloc(sizeof(t_mlx) * 5);
	background.walls[NORTH].img = NULL;
	background.walls[SOUTH].img = NULL;
	background.walls[WEST].img = NULL;
	background.walls[EAST].img = NULL;
    fill_background_struct(cub3d, &background);
    return (background);
}