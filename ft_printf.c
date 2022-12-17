/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:56:14 by smagalha          #+#    #+#             */
/*   Updated: 2022/12/17 23:04:12 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_putstr_fd.c"
#include "ft_putnbr_fd.c"

int	handleSpecifier(char specifier, va_list argumento)
{
	if (specifier == 's')
		ft_putstr_fd(va_arg(argumento, char *), 1);
	if (specifier == 'i')
		ft_putnbr_fd(va_arg(argumento, int), 1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		argumentos;
	int			i;

	i = 0;
	va_start(argumentos, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			handleSpecifier(s[i], argumentos);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(argumentos);
}

void	main(void)
{
	char string1[] = "Uma casinha muito linda";
	int numero = 5;

	ft_printf("Uma string de teste: %i", numero);
}

//cspdiuxX%

/* 
c = character
s = string
p = Pointer address
d = signed decimal integer
i = integer
u = Unsigned decimal integer
x = Unsigned hexadecimal integer
X = Unsigned hexadecimal integer (capital letters)
% = Character

*/