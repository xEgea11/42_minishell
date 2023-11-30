/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:48:59 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/19 16:28:48 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(long n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoalong(long n)
{
	char			*str;
	size_t			len;
	long int		n_long;

	n_long = n;
	len = ft_num_len(n);
	if (n < 0)
	{
		n_long *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n_long % 10 + '0';
		n_long /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
