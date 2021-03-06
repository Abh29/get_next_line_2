#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	size;
	char	*save;

	size = ft_strlen(s1);
	out = (char *)malloc(size + 1);
	if (out == NULL)
		return (NULL);
	save = out;
	while (*s1)
		*out++ = *s1++;
	*out = 0;
	return (save);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*save;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	out = malloc(size + 1);
	if (out == NULL)
		return (NULL);
	save = out;
	while (*s1)
		*out++ = *s1++;
	while (*s2)
		*out++ = *s2++;
	*out = '\0';
	return (save);
}
