/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#include "include/frambuffer.h"
#include "include/my.h"

void initialise_map(char **argv, map_t *map_struct)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    map_struct->map = malloc(sizeof(char *) * (map_struct->j + 1));
    close(map_struct->fd);
    line = malloc(sizeof(char) * map_struct->i);
    fp = fopen(argv[1], "r");
    while (map_struct->k < map_struct->j) {
        getline(&line, &len, fp);
        map_struct->map[map_struct->k] = my_strdupp(line);
        map_struct->k++;
    }
    map_struct->map[map_struct->k-1] = NULL;
    free(line);
}

int start_map(char **argv, map_t *map_struct)
{
    char tmp[300];

    map_struct->j = 0;
    map_struct->i = 0;
    map_struct->k = 0;
    map_struct->fd = open(argv[1], O_RDONLY);
    if (map_struct->fd < 0)
        return (84);
    while (read(map_struct->fd, &map_struct->car, 1) > 0) {
        map_struct->i++;
        if (map_struct->car == '\n')
            break;
    }
    close(map_struct->fd);
    map_struct->fd = open(argv[1], O_RDONLY);
    for (int zbub = 1; zbub > 0; map_struct->j++) {
        zbub = read(map_struct->fd, tmp, map_struct->i);
    }
    initialise_map(argv, map_struct);
}

char *my_strdupp(char const *src)
{
    int src_len = my_strlenn(src);
    char *res;

    res = malloc(src_len * sizeof(char));
    my_strcpyy(res, src);
    return (res);
}

int my_strlenn(char const *str)
{
    char i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strcpyy(char *dest, char const *src)
{
    dest[my_strlenn(src)] = '\0';

    for (char i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (dest);
}