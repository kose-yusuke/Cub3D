#include "cub3d.h"

static void	validate_setting(char *id, char *setting, t_check_list *check_list)
{
	int	len;

	if (ft_strncmp(id, "NO ", 3) == 0 && !check_list->north)
		check_list->north = is_valid_wallpaper(setting, check_list);
	else if (ft_strncmp(id, "SO ", 3) == 0 && !check_list->south)
		check_list->south = is_valid_wallpaper(setting, check_list);
	else if (ft_strncmp(id, "WE ", 3) == 0 && !check_list->west)
		check_list->west = is_valid_wallpaper(setting, check_list);
	else if (ft_strncmp(id, "EA ", 3) == 0 && !check_list->east)
		check_list->east = is_valid_wallpaper(setting, check_list);
	else if (ft_strncmp(id, "F ", 2) == 0 && !check_list->floor)
		check_list->floor = is_valid_color_setting(setting, check_list);
	else if (ft_strncmp(id, "C ", 2) == 0 && !check_list->ceiling)
		check_list->ceiling = is_valid_color_setting(setting, check_list);
	else
		check_list->invalid = true;
}

static void	check_data_content(char *line, t_check_list *check_list)
{
	char	*id;
	char	*setting;

	skip_space(&line);
	if (*line == '\n' || *line == '\0')
		return ;
	id = line;
	skip_nonspace(&line);
	skip_space(&line);
	if (*line == '\n' || *line == '\0')
	{
		check_list->invalid = true;
		return ;
	}
	setting = line;
	validate_setting(id, setting, check_list);
}

static bool	is_check_list_satisfied(t_check_list *check_list)
{
	if (check_list->invalid)
		return (false);
	if (check_list->north && check_list->south && check_list->west
		&& check_list->east && check_list->floor && check_list->ceiling)
		return (true);
	return (false);
}

bool	validate_map_data(int fd)
{
	t_check_list	check_list;
	char			*line;

	ft_bzero(&check_list, sizeof(t_check_list));
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			return (false);
		check_data_content(line, &check_list);
		free(line);
		if (check_list.invalid)
			return (false);
		if (is_check_list_satisfied(&check_list))
			return (true);
	}
}
