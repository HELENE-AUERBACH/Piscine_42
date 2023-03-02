/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:23:31 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:23 by hauerbac         ###   ########.fr       */
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
			if (i == range_len)
				return (ptr);
			else
				return (NULL);
		}
	}
	return (NULL);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_len;
	int	*ptr;

	if (range == NULL)
		return (-1);
	if (min < max)
	{
		range_len = max - min;
		ptr = ft_range(min, max);
		*range = ptr;
		if (ptr)
			return (range_len);
		else
			return (-1);
	}
	else
		return (0);
}
