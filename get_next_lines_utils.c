#include "get_next_lines.h"

char    *ft_strdup(char *s, char *str)
{
    int     i;
    int     size;

    i = 0;
    size = 0;
    while (s[size] != '\0')
        size++;
    //str = malloc(sizeof(char) * size + 1);
    while (s[i] != '\0')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;

    return (i);
}

char    *add_char(char c, char *str)
{
    int     size;
    char    *tmp;

    size = ft_strlen(str);
    tmp = strdup(str);
    free(str);
    str = malloc(sizeof(char) * (size + 2));
    str = tmp;
    tmp = NULL;
    str[size] = c;
    str[size + 1] = '\0';
    return (str);
}

int     word_count(char *str, char sep)
{
    int     i;
    int     nb;

    i = 0;
    nb = 0;
    while (str[i] != '\0')
    {
        if (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0')
            nb++;
        i++;
    }
    return (nb + 1);
}

char    *cut_str(char *s, int start, int end)
{
    int     i;
    char    *str;

    i = start;
    str = malloc(sizeof(char) * (end - start + 2));
    while (s[i] != '\0' && i <= end)
    {
        str[i - start] = s[i];
        i++;
    }
    str[i - start] = '\0';
    return (str);
}

char    **ft_split(char *str, char sep)
{
    int     i;
    int     esep;
    int     pos;
    char    **array;

    i = 0;
    esep = -1;
    pos = 0;
    array = malloc(sizeof(char*) * (word_count(str, sep) + 2));
    while (str[i] != '\0')
    {
        if (str[i] == sep)
        {
            array[pos] = cut_str(str, esep + 1, i - 1);
            esep = i;
            pos++;
        }
        if (str[i + 1] == '\0')
        {
            array[pos] = cut_str(str, esep + 1, i);
            esep = i;
            pos++;
        }
        i++;
    }
    array[pos] = NULL;
    return  (array);
}
