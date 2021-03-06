/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:39:29 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/09 15:12:44 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_fd
{
	char		*old;
	int			fd;
	struct s_fd	*next;
	struct s_fd *previous;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
