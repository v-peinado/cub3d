#include "cub3d.h"


void parse_input(int argv, char **argc, t_cub3d *cub3d)
{
    if (argv != 2)
        ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
    else if (ft_strncmp(argc[1] + ft_strlen(argc[1]) - 4, ".cub", 4) != 0)
        ft_putstr_fd("Error\nInvalid file extension\n", 2);
    else
        init_cub(cub3d);
}