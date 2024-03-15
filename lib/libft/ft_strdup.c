/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:48:13 by abausa-v          #+#    #+#             */
/*   Updated: 2023/10/03 09:36:13 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	if (result)
		ft_strlcpy(result, str, len + 1);
	return (result);
}
