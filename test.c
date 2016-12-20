#include "get_next_line.h"
#include <stdio.h>

t_fd	*gnl_new_fd(int fd)
{
	t_fd	*lst;

	lst = (t_fd *)malloc(sizeof(t_fd) * 1);
	(*lst).reste = NULL;
	(*lst).fd = fd;
	(*lst).next = NULL;
	return (lst);
}

int	get_next_line(const int fd, char **line)
{
	static t_fd	*lst = NULL;
//	char		buffer[BUFF_SIZE];
	int		n;
	int		i;

	if (lst == NULL)
		lst = gnl_new_fd(fd);
	else
	{
		while ((*lst).fd != fd && (*lst).next != NULL)
			lst++;
		if ((*lst).fd != fd)
		{
			(*lst).next = gnl_new_fd(fd);
			lst = (*lst).next;
		}
	}
//	*line = ft_strjoin(lst->reste, NULL);
//	printf("reste = %s, fd = %d, line = %s\n", lst->reste, lst->fd, line);
	*line = (*lst).reste;
	lst->reste = NULL;
	printf(" buffer = %s\n", lst->buffer);
	read(fd, lst->buffer, BUFF_SIZE);
//	printf(" buffer = %s\n", lst->buffer);
	n = 0;
	while(lst->buffer[n] != '\n' && lst->buffer[n] != '\0')
	{
		printf("reste = %s, line = %s, buffer = %s\n", lst->reste, *line, lst->buffer);
		n++;
		if (lst->buffer[n] == '\0')
		{
			*line = ft_strjoin(*line, ft_strsub(lst->buffer, 0, n));
			read(fd, lst->buffer, BUFF_SIZE);
			n = 0;
		}
		if (lst->buffer[n] == '\n' && lst->buffer[n + 1] != '\0')
		{
			*line = ft_strjoin(*line, ft_strsub(lst->buffer, 0, n));
			i = n + 1;
			while (lst->buffer[i] != '\0')
				i++;
			(*lst).reste = ft_strsub(lst->buffer, n + 1, (i - 1) - n);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int 	fd;
	int	fd2;
	char		**line;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	get_next_line((const int)fd, line);
	printf("line : %s\n", *line);
	get_next_line((const int)fd, line);
	printf("line : %s\n", *line);
	get_next_line((const int)fd, line);
	printf("line : %s\n", *line);
	get_next_line((const int)fd, line);
	printf("line : %s\n", *line);
	get_next_line((const int)fd, line);
	printf("line : %s\n", *line);
	return (0);
}