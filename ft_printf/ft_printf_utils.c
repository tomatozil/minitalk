//
// Created by jiyun on 2022/07/20.
//
#include <stdlib.h>

size_t  ft_strlen(const char *s)
{
	size_t  len;
	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char    *ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}