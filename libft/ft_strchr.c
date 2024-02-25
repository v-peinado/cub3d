/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:50:34 by vpeinado          #+#    #+#             */
/*   Updated: 2023/01/10 18:51:54 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char			*string;
	unsigned char	chr;

	string = (char *)str;
	chr = (unsigned char)c;
	while (*string)
	{
		if (*string == chr)
			return (string);
		string++;
	}
	if (*string == chr)
	{
		return (string);
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("Funcion propia: %s\n", ft_strchr("holo", '\0'));
	printf("Funcion original: %s", strchr("holo", '\0'));
}*/
