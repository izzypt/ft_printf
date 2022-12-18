/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:05:13 by smagalha          #+#    #+#             */
/*   Updated: 2022/12/18 19:16:03 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long n, const char ch)
{
	int			cont;
	const char	*hex;
	const char	*hexm;

	cont = 0;
	hex = "0123456789abcdef";
	hexm = "0123456789ABCDEF";
	if (n >= 16)
	{
		cont += ft_puthex(n / 16, ch);
		cont += ft_puthex(n % 16, ch);
	}
	if (n < 16)
	{
		if (ch == 'x')
			write(1, &hex[n], 1);
		else if (ch == 'X')
			write(1, &hexm[n], 1);
	}
	return (cont);
}
