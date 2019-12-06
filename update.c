/*
** EPITECH PROJECT, 2019
** update
** File description:
** update
*/

#include "include/frambuffer.h"
#include "include/my.h"

void update_game(map_t *map_struct, player_t *player)
{
    int nbr = map_struct->j - 1;

    map_struct->quit = 0;
    player->clear_order = 0;
    player->win = 0;
    while (map_struct->quit == 0) {
        attron(COLOR_PAIR(1));
        if (player->clear_order == 1) {
            clear();
            player->clear_order = 0;
        }
        for (int a = 0; a != nbr; a++)
            mvprintw(a, 0, map_struct->map[a]);
        attroff(COLOR_PAIR(1));
        get_button(map_struct, player);
        if (player->win == 1)
            break;
        refresh();
    }
}

void get_button(map_t *map_struct, player_t *player)
{
    map_struct->ch = getch();
    switch(map_struct->ch) {
        case KEY_LEFT:
            move_left(map_struct, player);
            break;
        case KEY_RIGHT:
            move_right(map_struct, player);
            break;
        case KEY_UP:
            move_up(map_struct, player);
            break;
        case KEY_DOWN:
            move_down(map_struct, player);
            break;
        case KEY_BACKSPACE:
            map_struct->quit = 1;
            break;
        default:
            break;
    }
}

int get_win(map_t *map_struct, player_t *player)
{
    player->nbr_win = 0;
    for (int i = 0; map_struct->map[i] != NULL; i++)
        for (int j = 0; map_struct->map[i][j] != '\0'; j++)
            set_win(map_struct, player, i, j);
    if (player->nbr_win == 0)
        return (1);
    else
        return (0);
}

void set_win(map_t *map_struct, player_t *player, int i, int j)
{
    if (map_struct->map[i][j] == 'O')
                player->nbr_win += 1;
}