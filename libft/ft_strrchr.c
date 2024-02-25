/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:21:05 by vpeinado          #+#    #+#             */
/*   Updated: 2023/01/10 19:18:50 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*string;
	unsigned char	chr;
	size_t			str_size;

	str_size = ft_strlen(str);
	string = (char *)str + str_size;
	chr = (unsigned char)c;
	while (str_size--)
	{
		if (*string == chr)
			return (string);
		string--;
	}
	if (*string == chr)
	{
		return (string);
	}	
	return (NULL);
}
/*\
int main (void)
{
	printf("%s\n", ft_strrchr("hololalelil", '\0'));
	printf("%s", ft_strrchr("hololalelil", '\0'));
}*/
