#include "cub3d.h"

void	skip_space(char **tmp)
{
	while (*tmp && **tmp == " ")
		*tmp++;
}

void	skip_nonspace(char **tmp)
{
	while (*tmp && **tmp != ' ')
		(*tmp)++;
}

bool	trim_trailing_space(char *str)
{
	skip_nonspace(&str);
	while (*str && (*str == ' ' || *str == '\n'))
	{
		*str = '\0';
		str++;
	}
	return (*str == '\0');
}

bool	is_valid_path(const char *path_copy)
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
