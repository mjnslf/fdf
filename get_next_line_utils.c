#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	int		a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}

void	*gnl_memcpy(void *dest, const void *srcs, size_t n)
{
	size_t	a;

	a = 0;
	if (!dest && !srcs)
		return (NULL);
	while (a < n)
	{
		((char *)dest)[a] = ((char *)srcs)[a];
		a++;
	}
	return (dest);
}

void	*gnl_memmove(void *dest, const void *srcs, size_t len)
{
	if (srcs < dest)
	{
		while (len--)
			((unsigned char *)dest)[len] = ((unsigned char *)srcs)[len];
	}
	else
		gnl_memcpy(dest, srcs, len);
	return (dest);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*total;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	len1 = gnl_strlen((char *)s1);
	len2 = gnl_strlen((char *)s2);
	total = malloc(len1 + len2 + 1);
	if (!total)
		return (0);
	gnl_memmove(total, s1, len1);
	gnl_memmove(total + len1, s2, len2);
	total[len1 + len2] = '\0';
	free((char *)s1);
	return (total);
}

char	*gnl_strdup(char *str)
{
	int		a;
	char	*total;

	a = 0;
	if (!str)
		return (0);
	total = malloc(sizeof(char) * (gnl_strlen(str) + 1));
	if (total == NULL)
		return (0);
	while (str[a] != '\0' && str[a] != '\n')
	{
		total[a] = str[a];
		a++;
	}
	total[a] = '\0';
	return (total);
}
