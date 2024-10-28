/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:16:13 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/28 12:01:51 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error_message_handler(char *message)
{
	printf("%s\n%s\n","Error",message);
	return (1);
}

int is_valid_char(char c)
{
	return (c == WALL || c == SPACE || c == PLAYER || c == NORTH || c == SOUTH || c == WEST || c == EAST);
}