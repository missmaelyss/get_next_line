#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int 	fd;
	int 	fd3;
	int		fd2;
	char	*line;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	printf("%d ", get_next_line(-99, NULL));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd, &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd, &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd, &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd2, &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd3, &line));
	printf("line doc #3: %s\n", line);
	printf("%d ", get_next_line((const int)fd, &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd2, &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd3, &line));
	printf("line doc #3: %s\n", line);
	return (0);
}
