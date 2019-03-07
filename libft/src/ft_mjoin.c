/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:01:48 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/08/28 16:04:20 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mjoin(int count, ...)
{
	va_list	args;
	va_list	args_copy;
	size_t	newstrlen;
	int		i;
	char	*ret;

	va_start(args, count);
	va_copy(args_copy, args);
	i = 0;
	newstrlen = 0;
	while (i++ < count)
		newstrlen += ft_strlen(va_arg(args, char*));
	va_end(args);
	ret = (char*)malloc(sizeof(char) * (newstrlen + 1));
	*ret = '\0';
	i = 0;
	while (i++ < count)
		ft_strcat(ret, va_arg(args_copy, char*));
	va_end(args_copy);
	return (ret);
}
