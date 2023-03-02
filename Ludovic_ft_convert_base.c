/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:43 by lucravoi          #+#    #+#             */
/*   Updated: 2023/02/23 15:55:04 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_base(char c, char *base);
int	ft_check_str(char *str, char *base);

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == 32 || base[i] == '+' || base[i] == '-' || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base, int i, int power)
{
	int	j;
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	if (!ft_check_str(str, base))
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	j = i;
	while (ft_is_in_base(str[i + 1], base) != -1)
		i++;
	while (i-- >= j)
	{
		number += (ft_is_in_base(str[i + 1], base) * power);
		power *= ft_check_base(base);
	}
	return (sign *= number);
}

int	ft_len(int nbr, int base_len)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		i++;
	}
	return (i + 1);
}

char	*ft_convert(int nbr, char *str, char *base)
{
	int	i;

	i = ft_len(nbr, ft_check_base(base));
	str[--i] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[--i] = base[nbr % ft_check_base(base)];
		nbr /= ft_check_base(base);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*str;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from, 0, 1);
	str = malloc(sizeof(char) * (ft_len(number, ft_check_base(base_to))));
	if (!str)
		return (NULL);
	*str = 0;
	if (number == 0 && ft_check_str(nbr, base_from))
	{
		str[0] = base_to[0];
		str[1] = '\0';
	}
	else
		str = ft_convert(number, str, base_to);
	return (str);
}
