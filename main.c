#include "get_next_line.h"
#include <stdio.h>

/*int	get_next_line(const int fd, char **line)
  {
  char	buffer[10];
  int	n;
  int	oui;
  char	*tmp;
  char	*tmp2;
  size_t	size;

  oui = 0;
  while (oui != 1)
  {
  n = 0;
  while (tmp[n] != '\n' && tmp[n] != '\0')
  {
  n++;
  if (tmp[n] == '\n')
  oui = 1;
  }
  read(fd, buffer, 10);
  n = 0;
  size = 0;
  while (buffer[n] != '\n' && n < 10)
  {
  if (buffer[n + 1] == '\n')
  oui = 1;
  size++;
  n++;
  }
  tmp2 = ft_strnew(size);
  tmp2 = ft_strncat(tmp2, buffer, size);
  tmp = ft_strjoin((char const *)tmp, (char const *)tmp2);
//		printf("%s", tmp);
}
printf("%s\n", tmp);
 *line = tmp;
 return (2);
 }
 */
int	get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE];
	size_t	size;
	size_t	n;

	char		*tmp;
//	char		*line;
	static char	*reste = NULL;

	n = 0;
	if (reste && reste[n + 1] != 0)
	{
		while (reste[n] != '\n' && reste[n] != '\0')
			n++;
		*line = ft_strnew(n);
		*line = ft_strncat(*line, reste, n);
		reste = ft_strsub(reste, n + 1, BUFF_SIZE - (n + 1));
//		printf("line = %s\nreste = %s\n", line, reste);	
	}
	else
	{
		*line = ft_strjoin(reste, NULL);

		read(fd, buffer, BUFF_SIZE);

//		printf("buffer = %s\nreste = %s\n", buffer, reste);
		size = 0;
		n = 0;	
		while (buffer[n] != '\n' && n < BUFF_SIZE && buffer[n] != '\0')
		{
			size++;
			n++;
			if (n == BUFF_SIZE)
			{
				tmp = ft_strnew(size);
				tmp = ft_strncat(tmp, buffer, size);
				*line = ft_strjoin(*line, tmp);
				read(fd, buffer, BUFF_SIZE);
				size = 0;
				n = 0;
			}
		}

		tmp = ft_strnew(size);
		tmp = ft_strncat(tmp, buffer, size);

		*line = ft_strjoin(*line, tmp);

		if (size + 1 < BUFF_SIZE)
			reste = ft_strsub(buffer, size + 1, BUFF_SIZE - (size + 1));
//		printf("size = %d\ntmp = %s\nline = %s\nreste = %s\n", size, tmp, line, reste);	
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
