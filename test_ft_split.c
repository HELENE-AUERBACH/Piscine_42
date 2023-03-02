/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:14:31 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/01 21:15:50 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char **tab;

	tab = ft_split("Ceci&est$un##############################################################################################################################################################succes@!", "&$#@");
	printf("%s\n", ft_strjoin(6, tab, " "));
	tab = ft_split("Success", "CUT");
	printf("%s\n", ft_strjoin(2, tab, " "));
	tab = ft_split("Success", "");
	printf("%s\n", ft_strjoin(2, tab, " "));
	tab = ft_split("", "");
	printf("OK\n");
	tab = ft_split( "", "CUT");
	printf("OK\n");
	tab = ft_split("       ", "       ");
	printf("OK\n");
	tab = ft_split("         ", "       ");
	printf("OK\n");
}
