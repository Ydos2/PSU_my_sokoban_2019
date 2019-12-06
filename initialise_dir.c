/*
** EPITECH PROJECT, 2019
** initialise_dir
** File description:
** initialise_dir
*/

#include "include/frambuffer.h"
#include "include/my.h"

void initialise_left(map_t *map_struct, player_t *player)
{
    if (map_struct->map[player->y][player->x-2] == ' ' ||
        map_struct->map[player->y][player->x-2] == 'O') {
            map_struct->map[player->y][player->x-2] = 'X';
            if (get_win(map_struct, player) == 1)
                player->win = 1;
            else
                get_defeat(map_struct, player, player->x-2, player->y);
        }
    else
        player->x += 1;
}

void initialise_right(map_t *map_struct, player_t *player)
{
    if (map_struct->map[player->y][player->x+2] == ' ' ||
        map_struct->map[player->y][player->x+2] == 'O') {
            map_struct->map[player->y][player->x+2] = 'X';
            if (get_win(map_struct, player) == 1)
                player->win = 1;
            else
                get_defeat(map_struct, player, player->x+2, player->y);
        }
    else
        player->x -= 1;
}

void initialise_up(map_t *map_struct, player_t *player)
{
    if (map_struct->map[player->y-2][player->x] == ' ' ||
        map_struct->map[player->y-2][player->x] == 'O') {
            map_struct->map[player->y-2][player->x] = 'X';
            if (get_win(map_struct, player) == 1)
                player->win = 1;
            else
                get_defeat(map_struct, player, player->x, player->y-2);
        }
    else
        player->y += 1;
}

void initialise_down(map_t *map_struct, player_t *player)
{
    if (map_struct->map[player->y+2][player->x] == ' ' ||
        map_struct->map[player->y+2][player->x] == 'O') {
            map_struct->map[player->y+2][player->x] = 'X';
            if (get_win(map_struct, player) == 1)
                player->win = 1;
            else
                get_defeat(map_struct, player, player->x, player->y+2);
        }
    else
        player->y -= 1;
}

void set_position_player(map_t *map_struct, player_t *player, int i, int j)
{
    if (map_struct->map[i][j] == 'P') {
        player->y = i;
        player->x = j;
    }
}