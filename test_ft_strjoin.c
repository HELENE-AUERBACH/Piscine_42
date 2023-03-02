/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:02:48 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/02 15:37:51 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	char	*strs[] = {"Toto", "TITUTA", "", "42"};
	char	*strs2[] = {"", "", ""};

	if (argc == 2)
	{
		printf("size == 4, sep == %s => %s\n", argv[1],
			ft_strjoin(4, strs, argv[1]));
		printf("size == 0, sep == %s => %s\n", argv[1],
			ft_strjoin(0, strs, argv[1]));
		printf("size == 3, sep == %s => %s\n", argv[1],
			ft_strjoin(0, strs2, argv[1]));
	}
	return (0);
}
