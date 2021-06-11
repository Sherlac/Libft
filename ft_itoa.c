/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:17:38 by cmariot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/10 12:30:02 by cmariot          ###   ########.fr       */
=======
/*   Updated: 2021/06/10 21:25:16 by cmariot          ###   ########.fr       */
>>>>>>> 09fe7fcea90338b7cadcf7968d8b8159a8574bb1
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
=======

static char	*special_case_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	else
		return (NULL);
}
>>>>>>> 09fe7fcea90338b7cadcf7968d8b8159a8574bb1

static int	int_len(int n)
{
	int	n_len;

	n_len = 0;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

static char	*int_to_array(int signe, char *nombre, int n, int n_len)
{
	nombre[n_len] = '\0';
	if (signe == 1)
		nombre[0] = '-';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}

char		*ft_itoa(int n)
{
	int		n_len;
	char	*nombre;
	int		signe;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	signe = 0;
	n_len = 0;
	if (n < 0)
	{
		n = -n;
		signe++;
		n_len++;
	}
	n_len += int_len(n);
	nombre = malloc(sizeof(char) * (n_len + 1));
	if (nombre == NULL)
		return (NULL);
	nombre = int_to_array(signe, nombre, n, n_len);
	return (nombre);
}
