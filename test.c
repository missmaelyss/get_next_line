#include "get_next_line.h"
#include <stdio.h>

t_fd	*gnl_new_fd(int fd)
{
	t_fd	*lst;

	lst = (t_fd *)malloc(sizeof(t_fd) * 1);
	(*lst).reste = NULL;
	(*lst).fd = fd;
	(*lst).next = NULL;
	(*lst).previous = NULL;
	return (lst);
}

int	get_next_line(const int fd, char **line)
{
	static t_fd	*lst = NULL;
//	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		n;
	int		i;

	if (lst == NULL)
		lst = gnl_new_fd(fd);
	else
	{
		if (lst->previous != NULL)
			lst = lst->previous;
		while ((*lst).fd != fd && (*lst).next != NULL)
			lst++;
		if ((*lst).fd != fd)
		{
			(*lst).next = gnl_new_fd(fd);
			(*lst).next->previous = lst;
			lst = (*lst).next;
		}
	}
/*	if (lst->next == NULL)
		printf("next = NULL, ");
	if (lst->previous == NULL)
		printf("previous = NULL, ");
	printf("reste = %s, fd = %d\n", lst->reste, lst->fd);
*/	
	int yolo = read(fd, lst->buffer, BUFF_SIZE);
//	printf("%d\n", yolo);
	lst->buffer[yolo] = '\0';
//	printf("%s\n", lst->buffer);	
	
	tmp = ft_strjoin(lst->reste, NULL);
//	printf("reste = %s, fd = %d, line = %s\n", lst->reste, lst->fd, tmp);
	lst->reste = NULL;
//	printf("reste = %s, fd = %d, line = %s\n", lst->reste, lst->fd, tmp);
//	printf(" buffer = %s\n", lst->buffer);
	read(fd, lst->buffer, BUFF_SIZE);
//	printf(" buffer = %s\n", lst->buffer);
	n = 0;
	while(lst->buffer[n] != '\n' && lst->buffer[n] != '\0' && n < BUFF_SIZE)
	{
	//	printf("reste = %s, line = %s, buffer = %s\n", lst->reste, tmp, lst->buffer);
		n++;
		if (lst->buffer[n] == '\0' || n == BUFF_SIZE)
		{
			tmp = ft_strjoin(tmp, ft_strsub(lst->buffer, 0, n));
			read(fd, lst->buffer, BUFF_SIZE);
			n = 0;
		}
		if (lst->buffer[n] == '\n' && lst->buffer[n + 1] != '\0')
		{
			tmp = ft_strjoin(tmp, ft_strsub(lst->buffer, 0, n));
			i = n + 1;
			while (lst->buffer[i] != '\0')
				i++;
			(*lst).reste = ft_strsub(lst->buffer, n + 1, (i - 1) - n);
		}
	}
	printf("%s\n", tmp);
	return (1);
}

int	main(int ac, char **av)
{
	int 	fd;
	int		fd2;
	int		fd3;
	char	**line;

	line = NULL;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	get_next_line((const int)fd, line);
	get_next_line((const int)fd2, line);
	get_next_line((const int)fd3, line);
	get_next_line((const int)fd, line);
	get_next_line((const int)fd2, line);
	get_next_line((const int)fd3, line);
/*	printf("line : %s\n", *line);
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
