/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:56:26 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/28 13:47:25 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

char	*ft_strncat_at_index(char *dest, char *src, unsigned int nb, int index)
{
	int		i;
	int		j;

	if (dest && src && nb > 0 && index >= 0)
	{
		i = index;
		j = 0;
		while ((unsigned int) j < nb && src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_cat_strs(int size, char **strs, char *sep, char *result)
{
	int	sep_len;
	int	i;
	int	j;

	sep_len = ft_strlen(sep);
	i = 0;
	j = 0;
	while (i < size && strs[i])
	{
		result = ft_strncat_at_index(result, strs[i], ft_strlen(strs[i]), j);
		j += ft_strlen(strs[i]);
		if (i != size - 1)
		{
			result = ft_strncat_at_index(result, sep, sep_len, j);
			j += sep_len;
		}
		i++;
	}
	if (j < ft_strlen(result))
		result[j] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		sep_len;
	int		strings_total_len;

	result = (char *) malloc(sizeof(char));
	if (result)
		result[0] = '\0';
	if (size > 0 && strs && sep && strs[0])
	{
		strings_total_len = 0;
		i = 0;
		while (i < size && strs[i])
			strings_total_len += ft_strlen(strs[i++]);
		sep_len = ft_strlen(sep);
		if (result)
			free(result);
		result = (char *) malloc((((size - 1) * sep_len)
					+ strings_total_len + 1) * sizeof(char));
		if (!result)
			return (NULL);
		result = ft_cat_strs(size, strs, sep, result);
	}
	return (result);
}
