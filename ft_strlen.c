/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:24:28 by smagalha          #+#    #+#             */
/*   Updated: 2022/12/17 22:39:21 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	return (counter);
}
