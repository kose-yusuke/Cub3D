#include "cub3d.h"

static bool	trim_trailing_space(char *str)
{
	skip_nonspace(&str);
	while (*str && (*str == ' ' || *str == '\n'))
	{
		*str = '\0';
		str++;
	}
	return (*str == '\0');
}

static bool	is_valid_path(const char *path_copy)
{
	int	fd;

	fd = open(path_copy, O_RDONLY);
	if (fd == -1)
	{
		ft_error_message_handler(strerror(errno));
		return (false);
	}
	close(fd);
	return (true);
}

bool	is_valid_wallpaper(char *path, t_check_list *check_list)
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
