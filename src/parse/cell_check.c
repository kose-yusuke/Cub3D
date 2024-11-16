/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:27:48 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:49 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_boundary_char(char c)
{
	return (c == '1' || c == ' ');
}

int	is_player_char(char cell)
{
	return (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E');
}

int	is_map_char(char c)
{
	return (c == '0' || is_boundary_char(c) || is_player_char(c));
}

bool	is_periphery_cell(int row, int col, int max_row, int max_col)
{
	return (row == 0 || row == max_row - 1 || col == 0 || col == max_col - 1);
}
