#include "cub3d.h"



static bool	is_valid_map_input(char *line)
{
	while (*line)
	{
		if (*line != ' ' && !is_valid_char(*line))
			return (false);
		line++;
	}
	return (true);
}

static void	update_flags(bool *is_valid_map, bool *in_map, char *line)
{
	if (*in_map)
	{
		if (is_blank_line(line))
			*in_map = false;
		else if (!is_valid_map_input(line))
			*is_valid_map = false;
		return ;
	}
	if (!is_blank_line(line))
		*is_valid_map = false;
}

static void	update_map_size(t_map *map, char *line, bool *is_valid_map)
{
	const size_t	line_len = ft_strlen(line);

	if (line_len > INT_MAX) // 行の長さが制限を超えるとだめ　INTMAXは大きいかも
	{
		*is_valid_map = false;
		return ;
	}
	// 最大列数を更新
	if (map->column < (int)line_len)
		map->column = (int)line_len;
	// 行数を更新
	map->row++;
}

bool	validate_map_figure(t_map *map, int fd)
{
	char	*line;
	bool	is_valid_map;
	bool	in_map;

	line = skip_blank_lines(fd); // map figure以前のblank lineは飛ばす
	is_valid_map = true;         // 不正なinputを見つけるまで、仮に正とする
	in_map = true;               // blank lineは飛ばしたので、map figure開始
	while (line)
	{
		update_flags(&is_valid_map, &in_map, line);
		if (is_valid_map && in_map)
		{
			update_map_size(map, line, &is_valid_map);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (map->row == 0 || map->column == 0)
		is_valid_map = false;
	return (is_valid_map);
}
