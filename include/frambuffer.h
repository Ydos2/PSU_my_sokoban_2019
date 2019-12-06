/*
** EPITECH PROJECT, 2019
** frambuffer_h
** File description:
** frambuffer
*/


#include <stdlib.h>

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

typedef struct map {
    char **map;
    int j;
    int i;
    int k;
    int fd;
    char car;
    int quit;
    int ch;
} map_t;

typedef struct player {
    int x;
    int y;
    int clear_order;
    int nbr_win;
    int win;
    int place_O;
} player_t;

void init_ncurses(void);
int verif_error(int row, int col, int argc, char **argv);
void close_param(map_t *map_struct);
void help(void);

void start_map(char **argv, map_t *map_struct);
void initialise_map(char **argv, map_t *map_struct);
char *my_strdupp(char const *src);
int my_strlenn(char const *str);
char *my_strcpyy(char *dest, char const *src);

void update_game(map_t *map_struct, player_t *player);
void get_button(map_t *map_struct, player_t *player);
int get_win(map_t *map_struct, player_t *player);
void set_win(map_t *map_struct, player_t *player, int i, int j);

void move_left(map_t *map_struct, player_t *player);
void move_right(map_t *map_struct, player_t *player);
void move_up(map_t *map_struct, player_t *player);
void move_down(map_t *map_struct, player_t *player);
void get_position_player(map_t *map_struct, player_t *player);

void initialise_left(map_t *map_struct, player_t *player);
void initialise_right(map_t *map_struct, player_t *player);
void initialise_up(map_t *map_struct, player_t *player);
void initialise_down(map_t *map_struct, player_t *player);
void set_position_player(map_t *map_struct, player_t *player, int i, int j);
#endif /*FRAMBUFFER_H_ */