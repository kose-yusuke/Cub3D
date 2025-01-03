/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:16:13 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/15 16:02:23 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_message_handler(char *message)
{
	printf("%s\n%s\n", "Error", message);
	return (1);
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
