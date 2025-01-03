/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:03:46 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/08 16:53:53 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_boundary_cell(t_map *map, char **grid, int x, int y)
{
	char	c_adjacent;

	if (grid[y][x] == '1')
		return (true);
	c_adjacent = '1';
	if (y == 0)
		c_adjacent = grid[y + 1][x];
	else if (y == map->row - 1)
		c_adjacent = grid[y - 1][x];
	else if (x == 0)
		c_adjacent = grid[y][x + 1];
	else if (x == map->column - 1)
		c_adjacent = grid[y][x - 1];
	if (!is_boundary_char(grid[y][x]) || !is_boundary_char(c_adjacent))
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
	mgr->map.grid[y][x] = '0';
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
			if (!check_boundary_cell(&mgr->map, mgr->map.grid, x, y))
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
