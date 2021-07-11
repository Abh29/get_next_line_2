#include "get_next_line.h"
#include <stdio.h>

static int	ft_handle_rest(char **line, char **rest)
{
	char	*ln;

	if (*rest)
	{
		ln = ft_strchr(*rest, '\n');
		if (ln)
		{
			*ln = 0;
			*line = ft_strdup(*rest);
			ln = ft_strdup(ln + 1);
			free(*rest);
			getchar();
			if (*ln)
				*rest = ft_strdup(ln);
			free(ln);
			ln = NULL;
			return (1);
		}
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

static int	ft_hahdnle_new_read(char *buff, char **line, char **rest)
{
	char	*nl;
	int		out;

	out = 0;
	nl = ft_strchr(buff, '\n');
	if (nl)
	{
		*nl = 0;
		*rest = ft_strdup(nl + 1);
		nl = NULL;
		out = 1;
	}
	if (*line == NULL)
		*line = ft_strdup(buff);
	else
		*line = ft_strjoin(*line, buff);
	return (out);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	int				size;
	char			*line;
	char			*buff;

	//printf("this is the rest %s", rest);
	//getchar();
	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (ft_handle_rest(&line, &rest))
		return (line);
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (1)
	{
		size = read(fd, buff, BUFFER_SIZE);
		//printf("this is size %d\n", size);
		if (size <= 0)
			break ;
		buff[size] = 0;
		if (ft_hahdnle_new_read(buff, &line, &rest) || size < BUFFER_SIZE)
			break ;
	}
	free(buff);
	buff = NULL;
	return (line);
}
