#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
typedef struct s_list
{
	char			*line;
	int				size;
	struct s_list	*next;
}				t_string_list;

char			*get_next_line(int fd);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif