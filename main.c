#include "get_next_lines.h"

int get_next_line(int fd, char **line)
{
    static char *contents;
    static int  index;
    static int  first_call;
    static char **splitted;
    char        buffer[2];

    if (first_call != 1)
    {
        index = 0;
        contents = malloc(sizeof(char) * 1);
        if (contents == NULL)\
            return (-1);
        contents[0] = '\0';
        while (read(fd, buffer, 1))
        {
            buffer[1] = '\0';
            contents = add_char(buffer[0], contents);
        }
        splitted = ft_split(contents, '\n');
        first_call = 1;
    }
    if (splitted[index] != NULL)
    {
        *line = splitted[index];
        index++;
        return (1);
    }
    return (0);
}

int main()
{
    char    *str;
    int     i;
    int     fd;

    i = 1;
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &str) > 0)
    {
        printf("Line %d : %s\n", i, str);
        i++;
    }
    return (1);
}
