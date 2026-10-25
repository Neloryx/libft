/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strmapi.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: thdeglos <thdeglos@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:32:39 by thdeglos         #+#    #+#              */
/*   Updated: 2026/10/19 12:32:39 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstring;

	if (!s || !f)
		return (NULL);
	nstring = malloc(ft_strlen(s) + 1);
	if (!nstring)
		return (NULL);
	i = 0;
	while (s[i])
	{
		nstring[i] = f(i, s[i]);
		i++;
	}
	nstring[i] = '\0';
	return (nstring);
}
