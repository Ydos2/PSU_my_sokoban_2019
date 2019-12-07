/*
** EPITECH PROJECT, 2019
** box
** File description:
** box
*/

#include "include/frambuffer.h"
#include "include/my.h"

void get_box(map_t *map_struct, player_t *player)
{
    player->nbr_X = 0;
    for (int i = 0; map_struct->map[i] != NULL; i++)
        for (int j = 0; map_struct->map[i][j] != '\0'; j++)
            set_box(map_struct, player, i, j);
}

void set_box(map_t *map_struct, player_t *player, int i, int j)
{
    if (map_struct->map[i][j] == 'X')
                player->nbr_X += 1;
}