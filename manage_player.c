/*
** EPITECH PROJECT, 2019
** manage_player
** File description:
** manage_player
*/

#include "include/frambuffer.h"
#include "include/my.h"

void move_left(map_t *map_struct, player_t *player)
{
    get_position_player(map_struct, player);
    if (map_struct->map[player->y][player->x-1] == '#') {
    } else {
        if (map_struct->map[player->y][player->x-1] == 'X')
            initialise_left(map_struct, player);
        if (map_struct->map[player->y][player->x-1] == 'O')
            player->place_O = 2;
        if (player->place_O == 1) {
            map_struct->map[player->y][player->x] = 'O';
            player->place_O = 0;
        } else
            map_struct->map[player->y][player->x] = ' ';
        player->x -= 1;
        map_struct->map[player->y][player->x] = 'P';
        player->clear_order = 1;
        if (player->place_O == 2)
            player->place_O = 1;
    }
}

void move_right(map_t *map_struct, player_t *player)
{
    get_position_player(map_struct, player);
    if (map_struct->map[player->y][player->x+1] == '#') {
    } else {
        if (map_struct->map[player->y][player->x+1] == 'X')
            initialise_right(map_struct, player);
        if (map_struct->map[player->y][player->x+1] == 'O')
            player->place_O = 2;
        if (player->place_O == 1) {
            map_struct->map[player->y][player->x] = 'O';
            player->place_O = 0;
        } else
            map_struct->map[player->y][player->x] = ' ';
        player->x += 1;
        map_struct->map[player->y][player->x] = 'P';
        player->clear_order = 1;
        if (player->place_O == 2)
            player->place_O = 1;
    }
}

void move_up(map_t *map_struct, player_t *player)
{
    get_position_player(map_struct, player);
    if (map_struct->map[player->y-1][player->x] == '#') {
    } else {
        if (map_struct->map[player->y-1][player->x] == 'X')
                initialise_up(map_struct, player);
        if (map_struct->map[player->y-1][player->x] == 'O')
            player->place_O = 2;
        if (player->place_O == 1) {
            map_struct->map[player->y][player->x] = 'O';
            player->place_O = 0;
        } else
            map_struct->map[player->y][player->x] = ' ';
        player->y -= 1;
        map_struct->map[player->y][player->x] = 'P';
        player->clear_order = 1;
        if (player->place_O == 2)
            player->place_O = 1;
    }
}

void move_down(map_t *map_struct, player_t *player)
{
    get_position_player(map_struct, player);
    if (map_struct->map[player->y+1][player->x] == '#') {
    } else {
        if (map_struct->map[player->y+1][player->x] == 'X')
            initialise_down(map_struct, player);
        if (map_struct->map[player->y+1][player->x] == 'O')
            player->place_O = 2;
        if (player->place_O == 1) {
            map_struct->map[player->y][player->x] = 'O';
            player->place_O = 0;
        } else
            map_struct->map[player->y][player->x] = ' ';
        player->y += 1;
        map_struct->map[player->y][player->x] = 'P';
        player->clear_order = 1;
        if (player->place_O == 2)
            player->place_O = 1;
    }
}

void get_position_player(map_t *map_struct, player_t *player)
{
    player->x = 0;
    player->y = 0;

    for (int i = 0; map_struct->map[i] != NULL; i++)
        for (int j = 0; map_struct->map[i][j] != '\0'; j++)
            set_position_player(map_struct, player, i, j);
}