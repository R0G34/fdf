/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:39:30 by abausa-v          #+#    #+#             */
/*   Updated: 2023/10/04 11:50:19 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_num(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n && ++i)
		n /= base;
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*result;
	const char	*nums = "0123456789";

	len = len_num(n, 10);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
	while (n)
	{
		if (n > 0)
			result[--len] = nums[n % 10];
		else
			result[--len] = nums[n % 10 * -1];
		n /= 10;
	}
	return (result);
}
