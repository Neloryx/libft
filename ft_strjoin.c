/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: thdeglos <thdeglos@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:32:37 by thdeglos         #+#    #+#              */
/*   Updated: 2026/10/19 12:32:37 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstring;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	nstring = malloc(lens1 + lens2 + 1);
	if (!nstring)
		return (NULL);
	ft_memcpy(nstring, s1, lens1);
	ft_memcpy(nstring + lens1, s2, lens2);
	nstring[lens1 + lens2] = '\0';
	return (nstring);
}
