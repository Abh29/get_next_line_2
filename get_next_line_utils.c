#include "get_next_line.h"

void	printlist(t_string_list *lst)
{
	while (lst)
	{
		printf("|%s| ", lst->line);
		lst = lst->next;
	}
	printf("\n");
}

int	ft_strlen_(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_string_list	*ft_lstnew(char *content)
{
	t_string_list	*out;

	out = malloc(sizeof(t_string_list));
	if (out == NULL)
		return (NULL);
	out->size = ft_strlen_(content);
	out->line = ft_strdup_(content);
	out->next = NULL;
	return (out);
}

int	ft_string_size(t_string_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size += lst->size;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstclear(t_string_list **lst)
{
	t_string_list	*p;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		free(p->line);
		p = NULL;
	}
	free(*lst);
}

int	ft_lstadd_back(t_string_list **lst, char *line)
{
	t_string_list	*save;
	t_string_list	*new;

	new = ft_lstnew(line);
	if (new == NULL)
	{
		return (0);
	}
	if (*lst == NULL)
	{
		*lst = new;
		return (1);	
	}
	save = *lst;
	while (save->next)
		save = save->next;
	save->next = new;
	return (1);
}

int	ft_concat_strings(t_string_list *lst, char **buff)
{
	int	size;
	int	i;
	int	j;

	if (lst == NULL)
		return (0);
	if (buff == NULL)
		return (-1);
	size = ft_string_size(lst);
	*buff = malloc(size + 1);
	if (*buff == NULL)
		return (-1);
	(*buff)[size] = 0;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->line[j])
			(*buff)[i++] = lst->line[j++];
		lst = lst->next;
	}
	(*buff)[i] = 0;
	return (size);
}
