/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:03:46 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/07 15:20:34 by koseki.yusu      ###   ########.fr       */
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

static bool	check_inner_cell(char **grid, int x, int y, char c)
{
	if (!is_map_char(c))
	{
		print_error("Invalid character in map");
		return (false);
	}
	if (c != ' ')
		return (true);
	if (!is_boundary_char(grid[y - 1][x]) || !is_boundary_char(grid[y
			+ 1][x]) || !is_boundary_char(grid[y][x - 1])
		|| !is_boundary_char(grid[y][x + 1]))
	{
		print_error("Map not enclosed by walls");
		return (false);
	}
	return (true);
}

static bool	check_player_cell(t_mgr *mgr, int x, int y, int *spawn_count)
{
	char	cell;

	cell = mgr->map.grid[y][x];
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
	init_player(mgr, x, y, cell);
	return (true);
}

static bool	check_map_row(t_mgr *mgr, int y, int *spawn_count)
{
	int		x;
	char	cell;

	x = 0;
	while (x < mgr->map.column)
	{
		cell = mgr->map.grid[y][x];
		if (is_periphery_cell(y, x, mgr->map.row, mgr->map.column))
		{
			if (!check_boundary_cell(cell))
				return (false);
		}
		else
		{
			if (!check_inner_cell(mgr->map.grid, x, y, cell))
				return (false);
			if (!check_player_cell(mgr, x, y, spawn_count))
				return (false);
		}
		x++;
	}
	return (true);
}

bool	check_map_validity(t_mgr *mgr)
{
	int	spawn_count;
	int	y;

	spawn_count = 0;
	y = 0;
	while (y < mgr->map.row)
	{
		if (!check_map_row(mgr, y, &spawn_count))
			return (false);
		y++;
	}
	if (spawn_count == 0)
	{
		print_error("No player found");
		return (false);
	}
	return (true);
}
