#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_gnl
{
	int		a;
	int		zero;
	char	*result;
	int		len;
}				t_gnl;

int				get_next_line(int fd, char **line);
size_t			gnl_strlen(const char *str);
void			*gnl_memcpy(void *dest, const void *srcs, size_t n);
void			*gnl_memmove(void *dest, const void *srcs, size_t len);
char			*gnl_strjoin(char const *s1, char const *s2);
char			*gnl_strdup(char *str);

#endif
