/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:50:54 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/23 09:50:57 by hauerbac         ###   ########.fr       */
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

int	ft_subranges(int **range, int range_len, int min, int max)
{
	int	*ptr;
	int	i;
	int	value;

	value = min;
	i = 0;
	while (i < range_len && value < max)
	{
		ptr = ft_range(min, max);
		if (ptr)
		{
			range[i++] = ptr;
			value++;
		}
		else
			return (-1);
	}
	if (i == range_len)
		return (range_len);
	else
		return (-1);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_len;
	int	nb;

	if (min < max)
	{
		range_len = max - min;
		range = (int **) malloc(range_len * sizeof(int *));
		if (range)
		{
			nb = ft_subranges(range, range_len, min, max);
			return (nb);
		}
		else
		{
			range = NULL;
			return (-1);
		}
	}
	else
	{
		range = NULL;
		return (0);
	}
}
