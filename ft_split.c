/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:46:27 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/01 20:55:25 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_char_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && charset[i] != c)
		i++;
	if (charset[i] == '\0')
		return (0);
	return (1);
}

int	ft_nb_substrs(char *str, char *charset)
{
	int	nb;
	int	i;

	if (str)
	{
		i = 1;
		nb = 0;
		while (str[i])
		{
			if (ft_char_is_sep(str[i], charset))
			{
				if (!ft_char_is_sep(str[i - 1], charset))
					nb++;
			}
			i++;
		}
		return (nb + !ft_char_is_sep(str[i - 1], charset));
	}
	return (0);
}

char	*substr_before_set_from_pos(char *str, int *pos, char *charset)
{
	int		i;
	char	*substr;

	if (str && charset && *pos >= 0 && !ft_char_is_sep(str[*pos], charset))
	{
		i = *pos;
		while (str[i] && !ft_char_is_sep(str[i], charset))
			i++;
		substr = (char *) malloc(sizeof(char) * (i - *pos + 1 + 1));
		if (!substr)
			return (NULL);
		i = 0;
		while (str[*pos] && !ft_char_is_sep(str[*pos], charset))
		{
			substr[i] = str[*pos];
			(*pos)++;
			i++;
		}
		substr[i] = '\0';
		while (str[*pos] && ft_char_is_sep(str[*pos], charset))
			(*pos)++;
		return (substr);
	}
	return (NULL);
}

void	ft_free_tab(char **split, int to_free_until)
{
	int	i;

	if (split)
	{
		i = 0;
		while (i < to_free_until)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

char	**ft_split(char *str, char *charset)
{
	int		nb_substrs;
	char	**tab;
	int		index_char;
	int		i;

	nb_substrs = ft_nb_substrs(str, charset);
	tab = (char **) malloc(sizeof(char *) * (nb_substrs + 1));
	if (!tab)
		return (NULL);
	index_char = 0;
	while (ft_char_is_sep(str[index_char], charset))
		index_char++;
	i = 0;
	while (i < nb_substrs)
	{
		tab[i] = substr_before_set_from_pos(str, &index_char, charset);
		if (!tab[i])
		{
			ft_free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
