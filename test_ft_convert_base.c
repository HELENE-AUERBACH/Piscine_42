/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_convert_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:53:06 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/02 16:04:00 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("42 en base 10: %s", ft_convert_base("42", "0123456789", "0123456789"));
	printf("\n2a == 42 en base 16: %s", ft_convert_base("2a", "0123456789abcdef", "0123456789"));
	printf("\n-2a == -42 en base 16: %s", ft_convert_base("-2a", "0123456789abcdef", "0123456789"));
	printf("\n (42 en base vide): %s", ft_convert_base("42", "0123456789", ""));
	printf("\n (42 en base de taille 1): %s", ft_convert_base("42", "0", "0123456789"));
	printf("\n (42 en base 16 avec + et -): %s", ft_convert_base("42", "0123456789", "+-0123456789abcdef"));
	printf("\n (42 en base 16 avec une tabulation): %s", ft_convert_base("42", "0123456789", "\t0123456789abcdef"));
	printf("\n101010 == 42 en base 2: %s", ft_convert_base("42", "0123456789", "01"));
	printf("\nvn == 42 en base 8 (\"poneyvif\"): %s", ft_convert_base("vn", "poneyvif", "0123456789"));
	printf("\n-2147483648 == −20000000000 en base 8 (\"01234567\"): %s", ft_convert_base("-2147483648", "0123456789", "01234567"));
	printf("\n2147483647 == 17777777777 en base 8 (\"01234567\"): %s", ft_convert_base("2147483647", "0123456789", "01234567"));
	printf("\n-2147483648 == −10000000000000000000000000000000 en base 2 (\"01\"): %s", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("\n2147483647 == 1111111111111111111111111111111 en base 2 (\"01\"): %s", ft_convert_base("2147483647", "0123456789", "01"));
	return (0);
}
