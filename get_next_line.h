#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

typedef struct	s_memory_fd
{
	char	*tmp;
	char	*tmp2;
	char	*rst;
	int	fd;
}		t_memory_fd;

# include <fcntl.h>
# include "libft/libft.h"

#endif
