/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:47:46 by llugez            #+#    #+#             */
/*   Updated: 2026/01/15 12:20:07 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(const char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_sep(str[i], sep))
		i++;
	while (str[i])
	{
		while (str[i] && !is_sep(str[i], sep))
			i++;
		count++;
		while (str[i] && is_sep(str[i], sep))
			i++;
	}
	return (count);
}

static char	*ft_allocword(const char *str, char *sep)
{
	int		len;
	int		i;
	char	*buffer;

	len = 0;
	i = 0;
	while (str[len] && !is_sep(str[len], sep))
		len++;
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (NULL);
	while (str[i] && !is_sep(str[i], sep))
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static void	*free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s1, char *sep)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = malloc(sizeof(char *) * (count_word(s1, sep) + 1));
	if (!buffer)
		return (NULL);
	while (*s1)
	{
		if (!is_sep(*s1, sep))
		{
			buffer[i] = ft_allocword(s1, sep);
			if (!buffer[i])
				return (free_tab(buffer, i));
			i++;
			while (*s1 && !is_sep(*s1, sep))
				s1++;
		}
		while (*s1 && is_sep(*s1, sep))
			s1++;
	}
	buffer[i] = NULL;
	return (buffer);
}

// int	main() {
// 	char **tab = ft_split(NULL, ' ');
// 	free(tab);
// }
