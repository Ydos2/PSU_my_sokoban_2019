/*
** EPITECH PROJECT, 2019
** sokoban_tools
** File description:
** sokoban_tools
*/

#include "include/frambuffer.h"
#include "include/my.h"

int set_end_game(player_t *player)
{
    if (player->win == 1)
        return (0);
    else
        return (1);
}

int define_caracter(map_t *map_struct)
{
    map_struct->result = 0;
    for (int i = 0; map_struct->map[i] != NULL; i++)
        for (int j = 0; map_struct->map[i][j] != '\0'; j++)
            set_caracter(map_struct, i, j);
    if (map_struct->result == 84)
        return (84);
    else
        return (0);
}

void set_caracter(map_t *map_struct, int i, int j)
{
    int a = 0;

    if (map_struct->map[i][j] == 'O')
        a = 1;
    if (map_struct->map[i][j] == 'X')
        a = 1;
    if (map_struct->map[i][j] == 'P')
        a = 1;
    if (map_struct->map[i][j] == '#')
        a = 1;
    if (map_struct->map[i][j] == '\n')
        a = 1;
    if (map_struct->map[i][j] == ' ')
        a = 1;
    if (a == 0)
        map_struct->result = 84;
}