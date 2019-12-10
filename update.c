/*
** EPITECH PROJECT, 2019
** update
** File description:
** update
*/

#include "include/frambuffer.h"
#include "include/my.h"

void update_game(map_t *map_struct, player_t *player, char **argv)
{
    int nbr = map_struct->j - 1, refresh_int = 0;

    initialise_value(map_struct, player);
    while (map_struct->quit == 0 || refresh_int == 1) {
        draw_map(map_struct, player, nbr);
        get_button(map_struct, player, argv);
        if (player->clear_order == 1) {
            clear();
            player->clear_order = 2;
        }
        if (refresh_int == 2) {
            refresh();
            break;
        }
        if (player->win == 1 || player->win == 2)
            refresh_int = 2;
        refresh();
    }
    draw_map(map_struct, player, nbr);
    refresh();
}

void get_button(map_t *map_struct, player_t *player, char **argv)
{
    map_struct->ch = getch();
    if (map_struct->ch == KEY_LEFT)
        move_left(map_struct, player);
    if (map_struct->ch == KEY_RIGHT)
        move_right(map_struct, player);
    if (map_struct->ch == KEY_UP)
        move_up(map_struct, player);
    if (map_struct->ch == KEY_DOWN)
        move_down(map_struct, player);
    if (map_struct->ch == KEY_BACKSPACE)
        map_struct->quit = 1;
    if (map_struct->ch == 32) {
        start_map(argv, map_struct);
        player->clear_order = 2;
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

void initialise_value(map_t *map_struct, player_t *player)
{
    map_struct->quit = 0;
    player->clear_order = 2;
    player->win = 0;
    get_box(map_struct, player);
}