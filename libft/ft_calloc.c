/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:20:04 by refernan          #+#    #+#             */
/*   Updated: 2026/07/28 14:37:08 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	total;

	if (nelem > 0 && elsize > 0)
	{
		if (nelem > ((size_t) - 1) / elsize)
			return (NULL);
	}
	total = nelem * elsize;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
