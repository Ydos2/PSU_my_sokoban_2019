/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include "./include/my.h"

void init_win_params(WIN *p_win)
{
    p_win->height = 0;
    p_win->width = 0;
    p_win->starty = (LINES - p_win->height)/2;
    p_win->startx = (COLS - p_win->width)/2;

    p_win->border.tl = 'P';
    p_win->border.ls = '#';
}

void create_box(WIN *p_win, bool flag)
{
    int i, j;
    int x, y, w, h;

    x = p_win->startx;
    y = p_win->starty;
    w = p_win->width;
    h = p_win->height;
    if (flag == TRUE) {
        attron(COLOR_PAIR(2));
        mvaddch(y, x, p_win->border.tl);
        attroff(COLOR_PAIR(2));
    }
    else
        for (j = y; j <= y + h; ++j)
            for (i = x; i <= x + w; ++i)
                mvaddch(j, i, ' ');
    refresh();
}

int main(int argc, char **argv)
{
    WIN win;
    int ch;
    int row, col;
    int fd;
    int x = 0;
    int y = 0;
    int y0 = 0;
    int quit = 0;
    char *tmp = 0;
    char **map;
    struct stat staaa;
    /*initscr();
    getmaxyx (stdscr, row, col);
    raw();
    start_color();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();*/

    /*if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        endwin();
        return (0);
    }*/
    if (row <= 15 || col <= 15 || argc != 2) {
        endwin();
        return (84);
    }

    stat(argv[1], &staaa);
    fd = open(argv[1], O_RDONLY);
    tmp = malloc(sizeof(char) * staaa.st_size+1);
    read(fd, tmp, staaa.st_size);
    tmp[staaa.st_size] = '\0';
    map = malloc(sizeof(char *) * (staaa.st_size+1));
    y0 = 0;
    for (int j = 0; tmp[j] != '\0'; j++)
        if (tmp[j] == '\n' || tmp[j+1] == '\0') {
            y0 = y0 + 1;
            map[y0] = malloc(sizeof(char *) * staaa.st_size+1);
        }
    int line = 0;
    int E = 0;
    for (int j = 0; tmp[j] != '\0'; j++, E++) {
        map[line][E] = tmp[j];
        if (tmp[j] == '\n') {
            map[line][E] = '\0';
            line++;
            E = 0;
        }
    }

    for (int i = 0; tmp[i] != '\0'; i++, x++) {
        if (tmp[i] == '\n') {
            map[y][x] = tmp[i];
            y++, x = 0;
        } else
            map[y][x] = tmp[i];
    }
/*
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_win_params(&win);
    print_win_params(&win);
    curs_set(0);
    while (quit == 0) {
        create_box(&win, TRUE);
        attron(COLOR_PAIR(1));
        mvprintw(LINES/2, (COLS/2)/2, "%s", tmp);
        attroff(COLOR_PAIR(1));
        refresh();
        while ((ch = getch()) != KEY_BACKSPACE) {
            switch(ch) {
            	case KEY_LEFT:
                    create_box(&win, FALSE);
                    --win.startx;
                    create_box(&win, TRUE);
                    break;
                case KEY_RIGHT:
                    create_box(&win, FALSE);
                    ++win.startx;
                    create_box(&win, TRUE);
                    break;
                case KEY_UP:
                    create_box(&win, FALSE);
                    --win.starty;
                    create_box(&win, TRUE);
                    break;
                case KEY_DOWN:
                    create_box(&win, FALSE);
                    ++win.starty;
                    create_box(&win, TRUE);
                    break;
                case KEY_BACKSPACE:
                    quit = 1;
                    break;
            }
        }
    }
    getch();
    endwin();
    return 0;*/
}

void help(void)
{
    write(1, "USAGE", 5);
    write(1, "\t./my_sokoban map", 18);
    write(1, "DESCRIPTION", 11);
    write(1, "\tmap file representing the warehouse map, containing '#' for walls,", 69);
    write(1, "\t\t'P' for the player, 'X' for boxes and '0' for storage locations.", 69);
}