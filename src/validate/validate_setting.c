#include "cub3d.h"

static bool	is_valid_wallpaper(char *path, t_check_list *check_list)
{
	char	*path_copy;

	path_copy = ft_strdup(path);
	if (!path_copy)
	{
		check_list->invalid = true;
		return (false);
	}
	if (!trim_trailing_space(path_copy) || !is_valid_path(path_copy))
	{
		check_list->invalid = true;
		free(path_copy);
		return (false);
	}
	free(path_copy);
	return (true);
}

static bool	is_valid_color(char *str, char **endptr)
{
	long	color;

	errno = 0;
	color = ft_strtol(str, endptr, 10);
	if (errno != 0 || color < 0 || color > 255)
		return (false);
	return (true);
}

static bool	is_valid_end(char **endptr, char expected_char)
{
	skip_space(endptr);
	return (**endptr == expected_char);
}

static bool	is_valid_color_setting(char *setting, t_check_list *check_list)
{
	char	*color;
	char	*endptr;

	color = setting;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, ','))
	{
		check_list->invalid = true;
		return (false);
	}
	color = endptr + 1;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, ','))
	{
		check_list->invalid = true;
		return (false);
	}
	color = endptr + 1;
	if (!is_valid_color(color, &endptr) || !is_valid_end(&endptr, '\0'))
	{
		check_list->invalid = true;
		return (false);
	}
	return (true);
}

void	validate_setting(char *id, char *setting, t_check_list *check_list)
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
