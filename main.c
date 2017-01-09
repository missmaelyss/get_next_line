#include "get_next_line/get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int 	*fd;
	char	*line;
	int		n;
	int		i;
	int		r;

	if (ac == 1)
		return (0);
	fd = (int *)malloc(sizeof(int) * (ac - 1));
	n = 1;
	while (n < ac )
	{
		fd[n - 1] = open(av[n], O_RDONLY);
		n++;
	}
	n = 1;
	while (n < ac )
	{
		printf("\n\ndoc #%d :\n", n);
		i = 1;
		r = get_next_line(fd[n - 1], &line);
		if (r == -1)
			printf("error\n");
		while (r > 0)
		{
			printf("line #%d : %s\n", i, line);
			i++;
			r = get_next_line(fd[n - 1], &line);
		}
		n++;
	}

/*	printf("%d ", get_next_line(-99, NULL));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd[0], &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd[0], &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd[0], &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd[1], &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd[2], &line));
	printf("line doc #3: %s\n", line);
	printf("%d ", get_next_line((const int)fd[0], &line));
	printf("line doc #1: %s\n", line);
	printf("%d ", get_next_line((const int)fd2, &line));
	printf("line doc #2: %s\n", line);
	printf("%d ", get_next_line((const int)fd3, &line));
	printf("line doc #3: %s\n", line);
*/	return (0);
}
