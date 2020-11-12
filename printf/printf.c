/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:51:01 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/12 21:00:33 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t 		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

int 	ft_numlen(long long n, int base_l)
{
	int i;

	i = 1;
	while (n >= base_l || n <= -base_l)
	{
		n /= base_l;
		i++;
	}
	return (i);
}

void 	ft_put_num(long long n, int base_l, char *base)
{
	if (n >= base_l)
		ft_put_num(n / base_l, base_l, base);
	write(1, &base[n % base_l], 1);
}

int 	ft_printf(const char *format, ...)
{
	va_list list;
	char 	*str, *s, *base;
	long 	num;
	int 	w = 0, p = 0, bolp = 0, n = 0, base_l = 0, len = 0, spc = 0, neg = 0, zero = 0;
	
	va_start(list, format);
	str = (char*)format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			w = 0, p = 0, bolp = 0, n = 0, spc = 0, neg = 0, zero = 0;
			while (*str >= '0' && *str <= '9')
			{
				w = w * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				str++;
				while (*str >= '0' && *str <= '9')
				{
					p = p * 10 + (*str - 48);
					str++;
				}
				bolp = 1;
			}
			if (*str == 's')
			{
				s = va_arg(list, char*);
				if (!s)
					s = "(null)";
				n = ft_strlen(s);
			}
			if (*str == 'x')
			{
				num = va_arg(list, unsigned);
				base = "0123456789abcdef";
				base_l = 16;
				n = ft_numlen(num, base_l);
			}
			if (*str == 'd')
			{
				num = va_arg(list, int);
				base = "0123456789";
				base_l = 10;
				if (num < 0)
				{
					num *= -1;
					neg = 1;
				}
				n = ft_numlen(num, base_l);
			}
			if (bolp == 1 && p >= n && *str != 's')
				zero = p - n + neg;
			else if (bolp == 1 && p < n && *str == 's')
				n = p;
			else if (bolp == 1 && p == 0 && (*str == 's' || num == 0))
				n = 0;
			spc = w - n - zero;
			while (spc-- > 0)
			{
				write(1, " ", 1);
				len++;
			}
			if (neg == 1)
				write(1, "-", 1);
			while (zero-- > 0)
			{
				write(1, "0", 1);
				len++;
			}
			if (*str == 's')
				write(1, s, n);
			else if (n > 0)
				ft_put_num(num, base_l, base);
			len += n;
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			len++;
		}
		
	}
	va_end(list);
	return (len);
}