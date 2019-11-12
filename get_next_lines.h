#ifndef GET_NEXT_LINES_H
#define GET_NEXT_LINES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int     get_next_line(int fd, char **line);
char    *ft_strdup(char *s, char *str);
int     ft_strlen(char *str);
char    *add_char(char c, char *str);
char    **ft_split(char *str, char sep);
int     word_count(char *str, char sep);
char    *cut_str(char *str, int start, int end);

#endif // GET_NEXT_LINES_H
