/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_ultimate_range.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:56:00 by hauerbac          #+#    #+#             */
/*   Updated: 2023/02/28 19:13:43 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

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

void	ft_print_int_tab_with_size(int **ptr_tab, int size)
{
	if (size > 0)
	{
		if (ptr_tab && *ptr_tab)
			ft_print_int_tab(*ptr_tab, size);
		printf("\nThe returned size of range is %d.\n", size);
		printf("ptr_tab = %p\n", ptr_tab);
	}
	else if (size == 0)
	{
		printf("\nNone array - Reason : If min >= max, range will point on NULL and it should return 0.\n");
		printf("The returned size of range is %d.\n", size);
	}
	else if (size == -1)
	{
		printf("\nIncomplete array - Reason : The size of range should be returned (or -1 on error).\n");
		printf("The returned size of range is %d.\n", size);
	}
	else
		printf("\nSegmentation fault - Reason : ptr_tab == (nil).");
}

int	main(void)
{
	int	min;
	int	max;
	int	**ptr1;
	int	tab1_size;
	int	**ptr2;
	int	tab2_size;
	int	**ptr3;
	int	tab3_size;
	int	**ptr4;
	int	tab4_size;
	int	*range1;
	int	*range2;
	int	*range3;

	ptr1 = (int **) malloc(sizeof(int *));
	if (ptr1)
	{
		min = 3;
		max = 8;
		printf("Pour min = %d et max = %d, tab1 =\n", min, max);
		tab1_size = ft_ultimate_range(ptr1, min, max);
		/*if (ptr1 && *ptr1)
		{
			printf("ptr1 = %p\n", ptr1);
			int i = 0;
			while (i < 5)
			{
				printf("%d, ", *(*ptr1 + i));
				i++;
			}
		}*/
		ft_print_int_tab_with_size(ptr1, tab1_size);
		if (ptr1)
			if (*ptr1)
				free(*ptr1);
		free(ptr1);
	}
	ptr2 = (int **) malloc(sizeof(int *));
	if (ptr2)
	{
		min = 42;
		max = 42;
		printf("\nPour min = %d et max = %d, tab2 =\n", min, max);
		tab2_size = ft_ultimate_range(ptr2, min, max);
		ft_print_int_tab_with_size(ptr2, tab2_size);
		free(ptr2);
	}
	ptr3 = (int **) malloc(sizeof(int *));
	if (ptr3)
	{
		min = -42;
		max = 43;
		printf("\nPour min = %d et max = %d, tab3 =\n", min, max);
		tab3_size = ft_ultimate_range(ptr3, min, max);
		ft_print_int_tab_with_size(ptr3, tab3_size);
		if (ptr3)
			if (*ptr3)
				free(*ptr3);
		free(ptr3);
	}
	ptr4 = (int **) malloc(sizeof(int *));
	if (ptr4)
	{
		min = 42;
		max = -1;
		printf("\nPour min = %d et max = %d, tab4 =\n", min, max);
		tab4_size = ft_ultimate_range(ptr4, min, max);
		ft_print_int_tab_with_size(ptr4, tab4_size);
		free(ptr4);
	}

	printf("\nWarn: Any segfault will mean that arrays are not correctly allocated\n");
	printf("5:%d\n", ft_ultimate_range(&range1, 0, 5));
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range1[0], range1[1], range1[2], range1[3], range1[4]);
	if (range1)
		free(range1);
	printf("0:%d\n", ft_ultimate_range(&range2, 3, 3));
	printf("2:%d\n", ft_ultimate_range(&range3, -1, 1));
	printf("-1, 0 : %d, %d", range3[0], range3[1]);
	if (range3)
		free(range3);
	return (0);
}
