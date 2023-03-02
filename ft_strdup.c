/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:07:10 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/24 10:27:09 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (src && dest && n > 0)
	{
		i = 0;
		while (i < n && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*ptr;

	if (src)
	{
		src_len = ft_strlen(src);
		ptr = (char *) malloc((src_len + 1) * sizeof(char));
		if (ptr)
		{
			ft_strncpy(ptr, src, src_len + 1);
			return (ptr);
		}
	}
	return (NULL);
}
