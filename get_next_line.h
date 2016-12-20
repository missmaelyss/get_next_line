#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

typedef struct	s_fd
{
	char		*reste;
	char		buffer[BUFF_SIZE];
	int		fd;
	struct s_fd	*next;
}		t_fd;

# include <fcntl.h>
# include "libft/libft.h"

#endif
