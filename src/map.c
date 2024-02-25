#include "cub3d.h"

#include <string.h>
#include <stdlib.h>

t_map map(t_cub3d *cub3d)
{
    t_map map;
    map.height = 13;
    map.matrix = malloc(sizeof(char *) * map.height);

    // Asignar memoria y copiar cada cadena
    map.matrix[0] = ft_strdup("1111111");
    map.matrix[1] = ft_strdup("1000001");
    map.matrix[2] = ft_strdup("100S001");
    map.matrix[3] = ft_strdup("1000001");
    map.matrix[4] = ft_strdup("1000001");
    map.matrix[5] = ft_strdup("1000001");
    map.matrix[6] = ft_strdup("1000001");
    map.matrix[7] = ft_strdup("1000001");
    map.matrix[8] = ft_strdup("1000001");
    map.matrix[9] = ft_strdup("1000001");
    map.matrix[10] = ft_strdup("1000001");
    map.matrix[11] = ft_strdup("1000001");
    map.matrix[12] = ft_strdup("1111111");
    map.width = 7;
    map.player_x = 3;
    map.player_y = 3;
    map.player_dir = 'S';
    return map;
}