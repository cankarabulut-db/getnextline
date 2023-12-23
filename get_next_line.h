#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char *ft_strjoin(char *s1, char *s2);
int ft_strchr(char *str, char c);
int ft_strlen(char *str);

#endif