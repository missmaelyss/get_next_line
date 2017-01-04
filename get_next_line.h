#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 8385223

typedef struct	s_fd
{
	char		*old;
	int		fd;
	struct s_fd	*next;
	struct s_fd *previous;
}		t_fd;

# include <fcntl.h>
# include "libft/libft.h"

#endif
