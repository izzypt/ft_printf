/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:41:23 by smagalha          #+#    #+#             */
/*   Updated: 2022/12/18 20:36:54 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddress(void *address)
{
	int		cont;
	char	*address_prefix;

	address_prefix = "0x";
	cont = 0;
	if (!address)
	{
		return (ft_putstr_fd("(nil)", 1));
	}
	cont += ft_putstr_fd(address_prefix, 1);
	cont += ft_puthex((int *) address, 'x');
	return (cont);
}