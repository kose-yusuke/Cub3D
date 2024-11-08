/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:03:46 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 20:06:54 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player_char(char cell)
{
	return (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E');
}

int	check_map_row(t_mgr *mgr, int i, int *spawn_count)
{
	int		j;
	char	cell;

	j = 0;
	while (j < mgr->map.column)
	{
		cell = mgr->map.grid[i][j];
		if (!is_valid_char(cell))
			return (ft_error_message_handler("Invalid character in map\n"));
		if (is_player_char(cell))
		{
			if (*spawn_count > 0)
				return (ft_error_message_handler("Many players in map\n"));
			*spawn_count = 1;
			init_player(mgr, i, j, cell);
		}
		j++;
	}
	return (1);
}

int	check_map_validity(t_mgr *mgr)
{
	int	spawn_count;
	int	i;

	spawn_count = 0;
	i = 0;
	while (i < mgr->map.row)
	{
		if (!check_map_row(mgr, i, &spawn_count))
			return (-1);
		i++;
	}
	if (spawn_count == 0)
		return (ft_error_message_handler("No player found\n"));
	return (0);
}
