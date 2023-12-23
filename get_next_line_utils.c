#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int ft_strchr(char *str, char c)
{
	int i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (*str == c)
			return (*str);
		str++;
		i--;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int b;
	char *ret;

	i = 0;
	b = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		ret[i + b] = s2[b];
		b++;
	}
	ret[i + b] = '\0';
	free(s1);
	return (ret);
}
