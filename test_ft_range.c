/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:56:00 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/22 19:07:10 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

void	ft_putnbr(int nb)
{
	long	nb_in_long;
	int		digit_to_char;

	nb_in_long = nb;
	if (nb_in_long < 0)
	{
		write(1, "-", 1);
		nb_in_long = nb_in_long * -1;
	}
	if (nb_in_long < 10)
	{
		digit_to_char = nb_in_long + '0';
		write(1, &digit_to_char, 1);
	}
	else
	{
		ft_putnbr(nb_in_long / 10);
		ft_putnbr(nb_in_long % 10);
	}
}

void	ft_print_int_tab(int *tab, int size)
{
	int	i;

	if (tab != NULL && size > 0)
	{
		write(1, "[", 1);
		i = 0;
		while (i < size)
		{
			ft_putnbr(tab[i]);
			if (i < size - 1)
				write(1, ", ", 2);
			i++;
		}
		write(1, "]", 1);
	}
}

int	main(void)
{
	int	min;
	int	max;
	int	*tab1;
	int	*tab2;
	int	*tab3;
	int	*tab4;

	min = 3;
	max = 8;
	tab1 = ft_range(min, max);
	printf("Pour min = %d et max = %d, tab1 =\n", min, max);
	ft_print_int_tab(tab1, max - min);
	free(tab1);
	min = 42;
	max = 42;
	tab2 = ft_range(min, max);
	printf("\nPour min = %d et max = %d, tab2 =\n", min, max);
	ft_print_int_tab(tab2, max - min);
	free(tab2);
	min = -42;
	max = 43;
	tab3 = ft_range(min, max);
	printf("\nPour min = %d et max = %d, tab3 =\n", min, max);
	ft_print_int_tab(tab3, max - min);
	free(tab3);
	min = 42;
	max = -1;
	tab4 = ft_range(min, max);
	printf("\nPour min = %d et max = %d, tab4 =\n", min, max);
	ft_print_int_tab(tab4, max - min);
	free(tab4);
	return (0);
}
