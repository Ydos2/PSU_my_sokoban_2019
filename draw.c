/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw
*/

#include "include/frambuffer.h"
#include "include/my.h"

void draw_map(map_t *map_struct, player_t *player, int nbr)
{
    if (player->clear_order == 2) {
        attron(COLOR_PAIR(1));
        for (int a = 0; a != nbr; a++)
            mvprintw(a, 0, map_struct->map[a]);
        attroff(COLOR_PAIR(1));
        player->clear_order = 0;
    }
}