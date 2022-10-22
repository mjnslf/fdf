#include "fdf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str++ = '\0';
		n--;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_atoi(const char *str)
{
	int		value;
	int		flag;
	int		i;

	value = 0;
	i = 0;
	flag = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		flag *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (flag * value);
}
