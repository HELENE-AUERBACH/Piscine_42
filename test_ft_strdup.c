/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:07:32 by hauerbac          #+#    #+#             */
/*   Updated: 2023/03/02 16:44:16 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*duplicated;

	duplicated = ft_strdup("Totototototot");
	printf("\"%s\" duplicated : \"%s\"\n", "Totototototot", duplicated);
	free(duplicated);
	duplicated = ft_strdup("");
	printf("\"%s\" duplicated : \"%s\"\n", "", duplicated);
	free(duplicated);
	duplicated = ft_strdup("1");
	printf("\"%s\" duplicated : \"%s\"\n", "1", duplicated);
	free(duplicated);
	duplicated = strdup("Totototototot");
	printf("\"%s\" duplicated : \"%s\"\n", "Totototototot", duplicated);
	free(duplicated);
	duplicated = strdup("");
	printf("\"%s\" duplicated : \"%s\"\n", "", duplicated);
	free(duplicated);
	duplicated = strdup("1");
	printf("\"%s\" duplicated : \"%s\"\n", "1", duplicated);
	free(duplicated);
	return (0);
}
