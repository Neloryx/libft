/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: thdeglos <thdeglos@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:32:23 by thdeglos         #+#    #+#              */
/*   Updated: 2026/10/20 08:42:45 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*n;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	n = malloc(nmemb * size);
	if (!n)
		return (NULL);
	ft_bzero(n, nmemb * size);
	return (n);
}
