/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:39:23 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/05 16:26:50 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_malloc_error(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

int	num_of_words(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

char	*next_str(char *s, char c)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s, i + 1);
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		strs_len;
	char	**tab;

	if (!s)
		return (NULL);
	strs_len = num_of_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (s[0] == c)
			s++;
		tab[i] = next_str(s, c);
		if (!tab[i])
			return (ft_malloc_error(tab));
		s = s + ft_strlen(tab[i]);
	}
	tab[i] = 0;
	return (tab);
}
