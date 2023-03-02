/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:33:49 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/02 16:05:07 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_atoi_base(char *str, char *base);

int	ft_error_or_strlen(const char *str)
{
	int	base_len;
	int	i;

	base_len = -1;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v')
			return (0);
		i++;
	}
	base_len = i;
	return (base_len);
}

int	ft_error_or_correct_base(const char *str, int base_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < base_len)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		else if (i > 0 && str[i])
		{
			j = 0;
			while (j < i && str[j])
			{
				if (str[j] == str[i])
					return (0);
				j++;
			}
		}
		i++;
	}
	if (i == base_len)
		return (base_len);
	return (0);
}

int	ft_error_or_base_len(const char *str)
{
	int	base_len;

	base_len = ft_error_or_strlen(str);
	if (base_len < 2)
		return (0);
	return (ft_error_or_correct_base(str, base_len));
}

char	*ft_itoa_base(char *result, int nb, char *base, int base_len)
{
	long	nb_into_long;
	int		i;

	nb_into_long = nb;
	i = 0;
	while (i < 33 && result[i] != '\0')
		i++;
	if (nb_into_long < 0)
	{
		result[i++] = '-';
		nb_into_long *= -1;
	}
	if (i < 33 && nb_into_long < base_len)
	{
		result[i++] = base[nb_into_long];
		result[i] = '\0';
	}
	else
	{
		ft_itoa_base(result, nb_into_long / base_len, base, base_len);
		ft_itoa_base(result, nb_into_long % base_len, base, base_len);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	int		nb_from_base_from;
	char	*result;
	int		i;

	base_from_len = ft_error_or_base_len(base_from);
	base_to_len = ft_error_or_base_len(base_to);
	if (base_from_len && base_to_len && nbr)
	{
		nb_from_base_from = ft_atoi_base(nbr, base_from);
		result = (char *) malloc((33 + 1) * sizeof(char));
		if (result)
		{
			i = 0;
			while (i < 33 + 1)
				result[i++] = '\0';
			return (ft_itoa_base(result, nb_from_base_from,
					base_to, base_to_len));
		}
		return (NULL);
	}
	return (NULL);
}
