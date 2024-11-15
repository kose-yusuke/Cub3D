/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:03:46 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/15 17:42:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_boundary_cell(char c)
{
	if (!is_boundary_char(c))
	{
		print_error("Map not enclosed by walls");
		return (false);
	}
	return (true);
}

static bool	check_inner_cell(char **grid, int row, int col, char c)
{
	if (!is_map_char(c))
	{
		print_error("Invalid character in map");
		return (false);
	}
	if (c != ' ')
		return (true);
	if (!is_boundary_char(grid[row - 1][col]) || !is_boundary_char(grid[row
			+ 1][col]) || !is_boundary_char(grid[row][col - 1])
		|| !is_boundary_char(grid[row][col + 1]))
	{
		print_error("Map not enclosed by walls");
		return (false);
	}
	return (true);
}

static bool	check_player_cell(t_mgr *mgr, int i, int j, int *spawn_count)
{
	char	cell;

	cell = mgr->map.grid[i][j];
	if (!is_player_char(cell))
	{
		return (true);
	}
	if (*spawn_count > 0)
	{
		print_error("Many players in map");
		return (false);
	}
	*spawn_count = 1;
	init_player(mgr, i, j, cell);
	return (true);
}

static bool	check_map_row(t_mgr *mgr, int i, int *spawn_count)
{
	int		j;
	char	cell;

	j = 0;
	while (j < mgr->map.column)
	{
		cell = mgr->map.grid[i][j];
		if (is_periphery_cell(i, j, mgr->map.row, mgr->map.column))
		{
			if (!check_boundary_cell(cell))
				return (false);
		}
		else
		{
			if (!check_inner_cell(mgr->map.grid, i, j, cell))
				return (false);
			if (!check_player_cell(mgr, i, j, spawn_count))
				return (false);
		}
		j++;
	}
	return (true);
}

bool	check_map_validity(t_mgr *mgr)
{
	int	spawn_count;
	int	i;

	spawn_count = 0;
	i = 0;
	while (i < mgr->map.row)
	{
		if (!check_map_row(mgr, i, &spawn_count))
			return (false);
		i++;
	}
	if (spawn_count == 0)
	{
		print_error("No player found");
		return (false);
	}
	return (true);
}
