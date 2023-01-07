/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:52:52 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/07 22:24:59 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	if (fd < 0)
		return (0);
	if (!s || !fd)
		return (0);
	write(fd, s, len);
	return (len);
}
