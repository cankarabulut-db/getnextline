#include <stdio.h>
#include "get_next_line.h"

char *ft_readline(int fd, char *dst)
{
	int readb;
	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readb = 1;
	while (!ft_strchr(dst, '\n') && readb != 0)
	{
		readb = read(fd,buff,BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			free(dst);
			return (NULL);
		}
		buff[readb] = '\0';
		dst = ft_strjoin(dst,buff);
	}
	free(buff);
	return (dst);
}

char *ft_getline(char *dst)
{
	char *ret;
	int i;

	i = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (dst[i] && dst[i] != '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	if (dst[i] == '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char *ft_leftline(char *dst)
{
	char *ret;
	int i;
	int b;

	i = 0;
	b = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(dst);
		return (NULL);
	}
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen(dst) - i + 1));
	if (!ret)
		return (NULL);
	while (dst[i])
	{
		ret[b] = dst[i];
		i++;
		b++;
	}
	ret[b] = '\0';
	free(dst);
	return (ret);
}

char *get_next_line(int fd)
{
	static char *dst;
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_readline(fd,dst);
	if (!dst)
		return (NULL);
	str = ft_getline(dst);
	dst = ft_leftline(dst);
	return (str);
}
#include <fcntl.h>
int main()
{
	int fd = open("a.txt",O_RDONLY);
	for (int x = 0; x < 1; x++)
	{
		printf("%s",get_next_line(fd));
	}
}