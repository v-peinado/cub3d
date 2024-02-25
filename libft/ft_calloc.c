/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:06:54 by vpeinado          #+#    #+#             */
/*   Updated: 2024/02/22 19:54:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;
	size_t	i;

	if (size  / size < nitems)
		return (NULL);
	pointer = (void *) malloc(nitems * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < nitems * size)
	{
		*(unsigned char *)(pointer + i) = 0;
		i++;
	}
	return (pointer);
}
