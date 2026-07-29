/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:52:41 by renan             #+#    #+#             */
/*   Updated: 2026/07/28 14:39:35 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(unsigned char *t, unsigned char *f, size_t size)
{
	while (size > 0)
	{
		size--;
		t[size] = f[size];
	}
	return (t);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		ft_memrcpy((unsigned char *)dest, (unsigned char *)src, n);
	return (dest);
}
