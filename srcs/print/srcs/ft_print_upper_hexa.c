/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

unsigned int	ft_uitoupperhexa_len(unsigned int n)
{
	unsigned int	n_len;
	unsigned int	diviseur;

	n_len = 0;
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		n_len++;
		diviseur = diviseur / 16;
	}
	return (n_len);
}

char	*ft_uitoa_hexa_maj(unsigned int n)
{
	char			*base;
	unsigned int	diviseur;
	unsigned int	result;
	char			*str;
	int				i;

	str = malloc(sizeof(char) * (ft_uitoupperhexa_len(n) + 1));
	if (!str)
		return (NULL);
	base = "0123456789ABCDEF";
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	i = 0;
	while (diviseur > 0)
	{
		result = (n / diviseur) % 16;
		str[i++] = base[result];
		diviseur = diviseur / 16;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_hexa_maj(t_flags *flags, int fd)
{
	unsigned int	upper_hexa;
	char			*str;
	char			*str0x;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	upper_hexa = va_arg(flags->args, unsigned int);
	str = ft_uitoa_hexa_maj(upper_hexa);
	if (flags->hashtag && upper_hexa != 0)
	{
		str0x = ft_strjoin("0X", str);
		ft_print(str0x, flags, fd);
		free(str0x);
	}
	else
		ft_print(str, flags, fd);
	free(str);
}
