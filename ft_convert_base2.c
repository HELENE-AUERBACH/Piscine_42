/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:00:09 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/01 17:23:11 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_error_or_base_len(const char *str);

unsigned int	ft_spaces_truncating(const char *str)
{
	unsigned int	i;

	i = 0;
	if (str)
	{
		while (str[i]
			&& (str[i] == ' ' || str[i] == '\f'
				|| str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\t' || str[i] == '\v'))
			i++;
	}
	return (i);
}

int	ft_char_is_into_base(char *characters_for_base, char c, int base_len)
{
	int	i;
	int	result;

	result = 0;
	if (characters_for_base && c != '\0' && base_len > 0)
	{
		i = 0;
		while (i < base_len && characters_for_base[i])
		{
			if (c == characters_for_base[i])
				return (1);
			i++;
		}
	}
	return (result);
}

int	ft_error_or_sign(int boundaries[2], const char *str,
		char *base, int base_len)
{
	int	result;
	int	i;

	result = 0;
	boundaries[0] = -1;
	boundaries[1] = -2;
	if (str)
	{
		result = 1;
		i = ft_spaces_truncating(str);
		while (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (str[i] == '-')
				result = -1 * result;
			i++;
		}
		if (str[i] && ft_char_is_into_base(base, str[i], base_len))
			boundaries[0] = i;
		while (str[i] && ft_char_is_into_base(base, str[i], base_len))
			boundaries[1] = i++;
		if (boundaries[0] == -1 || boundaries[1] == -2
			|| boundaries[0] > boundaries[1])
			result = 0;
	}
	return (result);
}

int	c_in_10(char *characters_for_base, char c, int base_len)
{
	int	i;
	int	result;

	result = -1;
	if (characters_for_base && c != '\0' && base_len > 0)
	{
		i = 0;
		while (i < base_len && characters_for_base[i])
		{
			if (c == characters_for_base[i])
				return (i);
			i++;
		}
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	len;
	int	error_or_sign;
	int	i;
	int	boundaries[2];

	res = 0;
	len = ft_error_or_base_len(base);
	if (len)
	{
		error_or_sign = (long) ft_error_or_sign(boundaries, str, base, len);
		if (error_or_sign != 0)
		{
			i = boundaries[0];
			res = c_in_10(base, str[i++], len);
			while (i <= boundaries[1])
				res = (res * len) + c_in_10(base, str[i++], len);
			res *= error_or_sign;
		}
		if (res < INT_MIN || res > INT_MAX)
			return (0);
	}
	return (res);
}
