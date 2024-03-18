/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:29 by abausa-v          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:31 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*Returns value of integer from a string.*/
/*If there is no digits in string - return 0.*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int	ft_is_digit_hex(char ch)
{
	char	*digits;
	int		i;

	digits = "0123456789ABCDEF";
	i = 0;
	ch = ft_toupper(ch);
	while (digits[i])
	{
		if (ch == digits[i])
			return (ch);
		i++;
	}
	return (-1);
}

int	ft_atoi_hex(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	while (ft_is_digit_hex(str[i]) != -1)
	{
		if (ft_is_digit_hex(str[i]) >= '0' && ft_is_digit_hex(str[i]) <= '9')
			result = result * 16 + ft_is_digit_hex(str[i]) - 48;
		if (ft_is_digit_hex(str[i]) >= 'A' && ft_is_digit_hex(str[i]) <= 'F')
			result = result * 16 + (ft_is_digit_hex(str[i]) - 'A' + 10);
		i++;
	}
	return (sign * result);
}
