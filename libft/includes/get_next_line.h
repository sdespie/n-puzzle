/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:36:06 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 17:18:41 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "unistd.h"
# include "stdlib.h"
# include "libft.h"
# include "ft_printf.h"

int		get_next_line(const int fd, char **line);

#endif
