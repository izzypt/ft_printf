/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:56:14 by smagalha          #+#    #+#             */
/*   Updated: 2023/01/07 23:17:50 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list argumento)
{
	int	len;

	len = 0;
	if (!argumento)
		return (0);
	if (specifier == 'c')
		len = ft_putchar_fd(va_arg(argumento, int), 1);
	if (specifier == 's')
		len = ft_putstr_fd(va_arg(argumento, char *), 1);
	if (specifier == 'u')
		len = ft_putnbr_fd(va_arg(argumento, int), 1);
	if (specifier == 'i' || specifier == 'd')
		len = ft_putnbr_fd(va_arg(argumento, int), 1);
	if (specifier == 'x' || specifier == 'X')
		len = ft_puthex(va_arg(argumento, unsigned int), specifier);
	if (specifier == 'p')
		len = ft_putaddress(va_arg(argumento, unsigned long));
	if (specifier == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	argumentos;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(argumentos, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			len += handle_specifier(s[i], argumentos);
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	va_end(argumentos);
	return (len);
}
/*
int main(void)
{
    int	num = 42;
    int	*pointer1 = &num;

    ft_printf("Print pointer address: %p\n", (void*)pointer1);

    return (0);
}

//cspdiuxX%


c = character DONE
s = string DONE
p = Pointer address DONE
d = signed decimal integer DONE
i = integer DONE
u = Unsigned decimal integer = 0 to 4294967295
x = Unsigned hexadecimal integer DONE
X = Unsigned hexadecimal integer (capital letters) DONE
% = Character DONE

*/