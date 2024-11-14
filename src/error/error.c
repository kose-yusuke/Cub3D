/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:16:13 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/14 16:55:18 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_message_handler(char *message)
{
	printf("%s\n%s\n", "Error", message);
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E');
}

int	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	return (1);
}

void	error_exit(char *message)
{
	print_error(message);
	exit(EXIT_FAILURE);
}
