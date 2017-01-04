#include "get_next_line.h"
#include <stdio.h>

t_fd	*gnl_new_fd(int fd)
{
	t_fd	*lst;

	lst = (t_fd *)malloc(sizeof(t_fd) * 1);
	(*lst).old = NULL;
	(*lst).fd = fd;
	(*lst).next = NULL;
	(*lst).previous = NULL;
	return (lst);
}

void	fonction_1(char *line, t_fd *lst, const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\n')
		n++;
	line = ft_strjoin(line, ft_strsub(s, 0, n));
	lst->old = ft_strdup(&(s[n + 1]));
	printf("line = %s\n", line);
}

int		fonction_2(char *line, t_fd *lst, char *buffer)
{
//	printf("%s", lst->old);
	if ( lst->old != NULL && ft_strchr((const char *)lst->old, '\n'))
	{
//		printf("(1) ");
		fonction_1(line, lst, lst->old);
		return (1);
	}
	else if (ft_strchr((const char *)buffer, '\n'))
	{
//		printf("(2) ");
		fonction_1(lst->old, lst, buffer);
		return (1);
	}
	else
	{
//		printf("(3) ");
		lst->old = ft_strjoin(lst->old, buffer);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_fd	*lst = NULL;
	char		buffer[BUFF_SIZE + 1];

	*line = ft_strnew(1);
	if (fd == -1)
		return (-1);
	if (lst == NULL)
		lst = gnl_new_fd(fd);
	else
	{
		while (lst->previous != NULL)
			lst = lst->previous;	
		while ((*lst).fd != fd && (*lst).next)
			lst = lst->next;
		if ((*lst).fd != fd)
		{
			(*lst).next = gnl_new_fd(fd);
			(*lst).next->previous = lst;
			lst = (*lst).next;
		}
	}
	buffer[read(fd, buffer, BUFF_SIZE)] = '\0';
	while (fonction_2(*line, lst, (char *)buffer) != 1 && read(fd, buffer, BUFF_SIZE))
		buffer[read(fd, buffer, BUFF_SIZE)] = '\0';
	return (1);	
}

int	main(int ac, char **av)
{
	int 	fd;
	int		fd2;
	int		fd3;
	char	*line;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	printf ("%d, %d, %d\n", fd, fd2, fd3);
	printf("1 :");	get_next_line((const int)fd, &line);
	printf("2 :");	get_next_line((const int)fd2, &line);
	printf("3 :");	get_next_line((const int)fd3, &line);
	printf("1 :");	get_next_line((const int)fd, &line);
	printf("2 :");	get_next_line((const int)fd2, &line);
	printf("3 :");	get_next_line((const int)fd3, &line);
	printf("2 :");	get_next_line((const int)fd2, &line);
/*	get_next_line((const int)fd, line);
		get_next_line((const int)fd, line);
		get_next_line((const int)fd, line);
		get_next_line((const int)fd, line);
		get_next_line((const int)fd, line);
		*//*	printf("line : %s\n", *line);
				get_next_line((const int)fd, line);
				printf("line : %s\n", *line);
				get_next_line((const int)fd, line);
				printf("line : %s\n", *line);
				get_next_line((const int)fd, line);
				printf("line : %s\n", *line);
				get_next_line((const int)fd, line);
				printf("line : %s\n", *line);
				*/	return (0);
}
