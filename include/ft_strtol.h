/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:05:06 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/13 02:59:43 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOL_H
# define FT_STRTOL_H

# include "libft.h"
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

int		ft_isspace(int c);
bool	check_sign(const char **str);
bool	is_valid_digit(char c, int base);
long	ft_strtol(const char *str, char **endptr, int base);
#endif
