#include "cub3d.h"

t_raycast raycast(void)
{
    t_raycast	ray;

	ray.ray_dir_x = 0;
	ray.ray_dir_y = 0;
	ray.line_height = 0;
	ray.draw_from = 0;
	ray.draw_to = 0;
	ray.map_x = 0;
	ray.map_y = 0;
	ray.tex_x = 0;
	ray.tex_y = 0;
	ray.tex_step = 0;
	ray.tex_pos = 0;
	ray.tex_wall_x = 0;
	ray.side_dist_x = 0;
	ray.side_dist_y = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.perp_wall_dist = 0;
	ray.step_x = 0;
	ray.step_y = 0;
	ray.side_hit = false;
	ray.wall_hit = false;
	return (ray);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	ft_calc_tex_positions(t_cub3d *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (!ray->side_hit)
		ray->tex_wall_x = cub->player.pos_y + ray->perp_wall_dist \
			* ray->ray_dir_y;
	else
		ray->tex_wall_x = cub->player.pos_x + ray->perp_wall_dist \
			* ray->ray_dir_x;
	ray->tex_wall_x -= floor(ray->tex_wall_x);
	ray->tex_x = ray->tex_wall_x * 64;
	if (!ray->side_hit && ray->ray_dir_x > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side_hit && ray->ray_dir_y < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	ray->tex_step = 1.0 * 64 / ray->line_height;
	ray->tex_pos = (ray->draw_from - WIN_HEIGHT / 2 \
		+ ray->line_height / 2) * ray->tex_step;
}

static void	ft_draw_floor_ceiling(t_cub3d *cub, int x, int from)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y <= from)
			my_mlx_pixel_put(cub, x, y, cub->background.ceiling);
		else
			my_mlx_pixel_put(cub, x, y, cub->background.floor);
	}
}
int	ft_get_pixel_color(t_mlx *mlx, int x, int y)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x
			* (mlx->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}
static void	ft_apply_texture(t_cub3d *cub, int direction, int x)
{
	int	color;

	color = ft_get_pixel_color(&cub->background.walls[direction], \
		cub->raycast.tex_x, cub->raycast.tex_y);
	my_mlx_pixel_put(cub, x, cub->raycast.draw_from, color);
}
void	ft_draw_textures(t_cub3d *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ft_calc_tex_positions(cub);
	ft_draw_floor_ceiling(cub, x, ray->draw_from);
	while (ray->draw_from++ < ray->draw_to)
	{
		ray->tex_y = (int)ray->tex_pos & (64 - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side_hit && cub->player.pos_x < ray->map_x)
			ft_apply_texture(cub, SOUTH, x);
		else if (!ray->side_hit && cub->player.pos_x > ray->map_x)
			ft_apply_texture(cub, NORTH, x);
		else if (ray->side_hit && cub->player.pos_y < ray->map_y)
			ft_apply_texture(cub, EAST, x);
		else if (ray->side_hit && cub->player.pos_y > ray->map_y)
			ft_apply_texture(cub, WEST, x);
	}
}
void	ft_apply_dda_algorithm(t_cub3d *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->wall_hit = false;
	while (!ray->wall_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = false;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = true;
		}
		if (cub->map.matrix[ray->map_x][ray->map_y] == '1')
			ray->wall_hit = true;
	}
	if (!ray->side_hit)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
static void	ft_calc_line_height(t_cub3d *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_from = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_from < 0)
		ray->draw_from = 0;
	ray->draw_to = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_to >= WIN_HEIGHT)
		ray->draw_to = WIN_HEIGHT - 1;
}
static void	ft_init_dda_algorithm(t_cub3d *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.pos_y)
			* ray->delta_dist_y;
	}
}
static void	ft_init_ray_directions(t_cub3d *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->ray_dir_x = cub->player.dir_x + cub->player.plane_x * \
		(2 * x / (double)WIN_WIDTH - 1);
	ray->ray_dir_y = cub->player.dir_y + cub->player.plane_y * \
		(2 * x / (double)WIN_WIDTH - 1);
	ray->map_x = (int) cub->player.pos_x;
	ray->map_y = (int) cub->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = ft_abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = ft_abs(1 / ray->ray_dir_y);
}
void	ft_raycast(t_cub3d *cub)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		ft_init_ray_directions(cub, x);
		ft_init_dda_algorithm(cub);
		ft_apply_dda_algorithm(cub);
		ft_calc_line_height(cub);
		ft_draw_textures(cub, x);
	}
}
int	start_game(t_cub3d *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	ft_raycast(cub3d);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}