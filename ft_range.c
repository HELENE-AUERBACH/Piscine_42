/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:26:36 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/23 09:05:04 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range_len;
	int	*ptr;
	int	i;
	int	value;

	if (min < max)
	{
		range_len = max - min;
		ptr = (int *) malloc(range_len * sizeof(int));
		if (ptr)
		{
			value = min;
			i = 0;
			while (i < range_len && value < max)
				ptr[i++] = value++;
			return (ptr);
		}
	}
	return (NULL);
}
